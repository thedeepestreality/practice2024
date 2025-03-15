#include "complex.h"

Complex& Complex::operator+=(const Complex& right) {
	re_ += right.re_;
	im_ += right.im_;
	return *this;
}

Complex& Complex::operator*=(const Complex& right)
{
	double re = re_ * right.re_ - im_ * right.im_;
	double im = re_ * right.im_ + right.re_ * im_;
	re_ = re;
	im_ = im;
	return *this;
}

Complex& Complex::operator++() {
	return *this += Complex(1, 0);
}

Complex Complex::operator++(int) {
	Complex tmp = *this;
	++*this;
	return tmp;
}

double Complex::getRe() const {
	return re_;
}

double Complex::getIm() const {
	return im_;
}

Complex operator+(const Complex& left, const Complex& right) {
	Complex left_copy = left;
	return left_copy += right;
}

Complex operator*(const Complex& left, const Complex& right) {
	Complex left_copy = left;
	return left_copy *= right;
}

bool operator==(const Complex& left, const Complex& right) {
	return (left.getRe() == right.getRe()) && (left.getIm() == right.getIm());
}

bool operator>(const Complex& left, const Complex& right) {
	return (left.getRe() > right.getRe()) || ((left.getRe() == right.getRe()) && (left.getIm() > right.getIm()));
}

bool operator!=(const Complex& left, const Complex& right) {
	return !(left == right);
}

bool operator>=(const Complex& left, const Complex& right) {
	return (left == right) || (left > right);
}

bool operator<(const Complex& left, const Complex& right) {
	return !(left == right) && !(left > right);
}

bool operator<=(const Complex& left, const Complex& right) {
	return !(left > right);
}

// val.getRe();
// getRe(&val);

std::ostream& operator<<(std::ostream& out, const Complex& val) {
	out << '(' << val.re_ << ',' << val.im_ << "i)";
	return out;
}