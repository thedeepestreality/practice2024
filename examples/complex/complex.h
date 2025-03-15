#pragma once
#include <iostream>

class Complex {
private:
	double re_;
	double im_;
public:
	//Complex(double re = 0.0, double im = 0.0) : {
	//	re_ = re;
	//	im_ = im;
	//}
	/*explicit Complex(double re = 0.0, double im = 0.0) : re_(re), im_(im) {}*/
	Complex(double re = 0.0, double im = 0.0) : re_(re), im_(im) {}

	Complex& operator+=(const Complex& right);
	Complex& operator*=(const Complex& right);

	//Complex operator+(const Complex& right) {
	//	//double re = re_ + right.re_;
	//	//double im = im_ + right.im_;
	//	//return Complex(re, im);

	//	Complex left = *this;
	//	return left += right;
	//}

	Complex& operator++();
	Complex operator++(int);

	double getRe() const;
	double getIm() const;

	friend std::ostream& operator<<(std::ostream&, const Complex&);
};

Complex operator+(const Complex& left, const Complex& right);
Complex operator*(const Complex& left, const Complex& right);
bool operator==(const Complex& left, const Complex& right);
bool operator>(const Complex& left, const Complex& right);
bool operator!=(const Complex& left, const Complex& right);
bool operator>=(const Complex& left, const Complex& right);
bool operator<(const Complex& left, const Complex& right);
bool operator<=(const Complex& left, const Complex& right);
std::ostream& operator<<(std::ostream& out, const Complex& val);