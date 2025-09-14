#include "HugeInt.h"
#include <algorithm>
#include <fstream>
#include <climits>

// 构造函数
HugeInt::HugeInt() : number("0"), isNegative(false) {}

HugeInt::HugeInt(int num) {
	if (num < 0) {
		isNegative = true;
		num = -num;
	} else {
		isNegative = false;
	}
	number = std::to_string(num);
}

HugeInt::HugeInt(const std::string& str) {
	std::string s = str;
	isNegative = false;//设置为整数
	
	if (s.empty()) {
		number = "0";
		return;
	}
	
	// 处理符号
	if (s[0] == '-') {
		isNegative = true;
		s = s.substr(1);//移除负号
	} else if (s[0] == '+') {
		s = s.substr(1);//移除正号
	}
	
	// 检查有效数字
	if (s.find_first_not_of("0123456789") != std::string::npos) {
		throw std::invalid_argument("Invalid number string");
	}
	
	// 去除前导零
	size_t nonZeroPos = s.find_first_not_of('0');
	if (nonZeroPos == std::string::npos) {
		number = "0";
		isNegative = false;
		return;
	}
	number = s.substr(nonZeroPos);
}

// 拷贝构造函数
HugeInt::HugeInt(const HugeInt& other) : number(other.number), isNegative(other.isNegative) {}

// 赋值运算符
HugeInt& HugeInt::operator=(const HugeInt& other) {
	if (this != &other) {
		number = other.number;
		isNegative = other.isNegative;
	}
	return *this;
}

// 移除前导零
void HugeInt::removeLeadingZeros() {
	size_t nonZeroPos = number.find_first_not_of('0');
	if (nonZeroPos == std::string::npos) {
		number = "0";
		isNegative = false;
	} else {
		number = number.substr(nonZeroPos);
	}
}

// 规范化数字
void HugeInt::normalize() {
	removeLeadingZeros();
}

// 比较绝对值大小
int HugeInt::compareAbsolute(const HugeInt& a, const HugeInt& b) {
	if (a.number.length() != b.number.length()) {
		return a.number.length() < b.number.length() ? -1 : 1;
	}
	return a.number.compare(b.number);
}

// 绝对值相加
HugeInt HugeInt::addAbsolute(const HugeInt& a, const HugeInt& b) {
	std::string result;
	int carry = 0;
	int i = a.number.length() - 1;
	int j = b.number.length() - 1;
	
	while (i >= 0 || j >= 0 || carry > 0) {
		int digitA = (i >= 0) ? (a.number[i--] - '0') : 0;
		int digitB = (j >= 0) ? (b.number[j--] - '0') : 0;
		int sum = digitA + digitB + carry;
		carry = sum / 10;
		result.push_back((sum % 10) + '0');
	}
	
	std::reverse(result.begin(), result.end());
	return HugeInt(result);
}

// 绝对值相减 (a >= b)
HugeInt HugeInt::subtractAbsolute(const HugeInt& a, const HugeInt& b) {
	std::string result;
	int borrow = 0;
	int i = a.number.length() - 1;
	int j = b.number.length() - 1;
	
	while (i >= 0) {
		int digitA = a.number[i--] - '0' - borrow;
		int digitB = (j >= 0) ? (b.number[j--] - '0') : 0;
		borrow = 0;
		
		if (digitA < digitB) {
			digitA += 10;
			borrow = 1;
		}
		
		result.push_back((digitA - digitB) + '0');
	}
	
	std::reverse(result.begin(), result.end());
	HugeInt res(result);
	res.removeLeadingZeros();
	return res;
}

// 绝对值相乘
HugeInt HugeInt::multiplyAbsolute(const HugeInt& a, const HugeInt& b) {
	if (a.isZero() || b.isZero()) {
		return HugeInt(0);
	}
	
	int lenA = a.number.length();
	int lenB = b.number.length();
	std::vector<int> result(lenA + lenB, 0);
	
	for (int i = lenA - 1; i >= 0; i--) {
		for (int j = lenB - 1; j >= 0; j--) {
			int product = (a.number[i] - '0') * (b.number[j] - '0');
			int sum = product + result[i + j + 1];
			result[i + j + 1] = sum % 10;
			result[i + j] += sum / 10;
		}
	}
	
	std::string resStr;
	for (int num : result) {
		if (!(resStr.empty() && num == 0)) {
			resStr.push_back(num + '0');
		}
	}
	
	return resStr.empty() ? HugeInt(0) : HugeInt(resStr);
}

// 绝对值除法 (返回商和余数)
std::pair<HugeInt, HugeInt> HugeInt::divideAbsolute(const HugeInt& dividend, const HugeInt& divisor) {
	if (divisor.isZero()) {
		throw std::runtime_error("Division by zero");
	}
	
	if (compareAbsolute(dividend, divisor) < 0) {
		return {HugeInt(0), dividend};
	}
	
	HugeInt quotient;
	HugeInt remainder;
	
	for (char digit : dividend.number) {
		remainder.number.push_back(digit);
		remainder.removeLeadingZeros();
		
		int count = 0;
		while (compareAbsolute(remainder, divisor) >= 0) {
			remainder = subtractAbsolute(remainder, divisor);
			count++;
		}
		
		quotient.number.push_back(count + '0');
	}
	
	quotient.removeLeadingZeros();
	remainder.removeLeadingZeros();
	
	return {quotient, remainder};
}

// 算术运算符实现
HugeInt HugeInt::operator+(const HugeInt& other) const {
	HugeInt result;
	
	if (isNegative == other.isNegative) {
		result = addAbsolute(*this, other);
		result.isNegative = isNegative;
	} else {
		int cmp = compareAbsolute(*this, other);
		if (cmp > 0) {
			result = subtractAbsolute(*this, other);
			result.isNegative = isNegative;
		} else if (cmp < 0) {
			result = subtractAbsolute(other, *this);
			result.isNegative = other.isNegative;
		} else {
			result = HugeInt(0);
		}
	}
	
	result.normalize();
	return result;
}

HugeInt HugeInt::operator-(const HugeInt& other) const {
	return *this + (-other);
}

HugeInt HugeInt::operator*(const HugeInt& other) const {
	HugeInt result = multiplyAbsolute(*this, other);
	result.isNegative = isNegative != other.isNegative;
	result.normalize();
	return result;
}

HugeInt HugeInt::operator/(const HugeInt& other) const {
	auto [quotient, remainder] = divideAbsolute(*this, other);
	quotient.isNegative = isNegative != other.isNegative;
	quotient.normalize();
	return quotient;
}

HugeInt HugeInt::operator%(const HugeInt& other) const {
	auto [quotient, remainder] = divideAbsolute(*this, other);
	remainder.isNegative = isNegative;
	remainder.normalize();
	return remainder;
}

// 一元运算符
HugeInt HugeInt::operator-() const {
	HugeInt result(*this);
	if (!result.isZero()) {
		result.isNegative = !result.isNegative;
	}
	return result;
}

HugeInt& HugeInt::operator++() {
	*this = *this + HugeInt(1);
	return *this;
}

HugeInt HugeInt::operator++(int) {
	HugeInt temp(*this);
	++(*this);
	return temp;
}

HugeInt& HugeInt::operator--() {
	*this = *this - HugeInt(1);
	return *this;
}

HugeInt HugeInt::operator--(int) {
	HugeInt temp(*this);
	--(*this);
	return temp;
}

// 关系运算符
bool HugeInt::operator==(const HugeInt& other) const {
	return isNegative == other.isNegative && number == other.number;
}

bool HugeInt::operator!=(const HugeInt& other) const {
	return !(*this == other);
}

bool HugeInt::operator<(const HugeInt& other) const
{
	if (isNegative != other.isNegative) {
		return isNegative;
	}
	
	if (isNegative) {
		return compareAbsolute(*this, other) > 0;
	} else {
		return compareAbsolute(*this, other) < 0;
	}
}

bool HugeInt::operator<=(const HugeInt& other) const {
	return *this < other || *this == other;
}

bool HugeInt::operator>(const HugeInt& other) const {
	return !(*this <= other);
}

bool HugeInt::operator>=(const HugeInt& other) const {
	return !(*this < other);
}

// 类型转换
HugeInt::operator int() const {
	try {
		long long val = std::stoll((isNegative ? "-" : "") + number);
		if (val < INT_MIN || val > INT_MAX) {
			throw std::overflow_error("HugeInt value out of int range");
		}
		return static_cast<int>(val);
	} catch (...) {
		throw std::overflow_error("HugeInt value out of int range");
	}
}

HugeInt::operator std::string() const {
	return toString();
}

// 文件IO
void HugeInt::saveToFile(const std::string& filename) const {
	std::ofstream outFile(filename);
	if (outFile) {
		outFile << (isNegative ? "-" : "") << number;
	}
}
HugeInt HugeInt::loadFromFile(const std::string& filename) {
	std::ifstream inFile(filename);
	if (!inFile) {
		throw std::runtime_error("Cannot open file");
	}
	
	std::string numStr;
	inFile >> numStr;
	return HugeInt(numStr);
}

// 工具函数
std::string HugeInt::toString() const {
	return (isNegative ? "-" : "") + number;
}

bool HugeInt::isZero() const {
	return number == "0";
}

// 输入输出运算符
std::ostream& operator<<(std::ostream& os, const HugeInt& num) {
	os << (num.isNegative ? "-" : "") << num.number;
	return os;
}
std::istream& operator>>(std::istream& is, HugeInt& num){
	std::string s;
	is>>s;
	num=HugeInt(s);
	return is;
}





