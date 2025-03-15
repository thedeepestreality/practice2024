#pragma once
#include "complex.h"

class ComplexPoly {
private:
	Complex* coeffs_;
	size_t coeff_length_;
public:
	ComplexPoly(Complex a0 = Complex(0,0)) {
		coeffs_ = new Complex[1];
		coeff_length_ = 1;
		coeffs_[0] = a0;
	}

	ComplexPoly(Complex* coeffs, size_t length) {
		coeffs_ = new Complex[length];
		coeff_length_ = length;
		for (size_t idx = 0; idx < length; ++idx)
			coeffs_[idx] = coeffs[idx];
	}

	ComplexPoly(const ComplexPoly& right) : ComplexPoly(right.coeffs_, right.coeff_length_) {}

	ComplexPoly& operator=(const ComplexPoly& right) {
		if (this != &right) {
			delete[] coeffs_;
			coeff_length_ = right.coeff_length_;
			coeffs_ = new Complex[coeff_length_];
			for (size_t idx = 0; idx < coeff_length_; ++idx)
				coeffs_[idx] = right.coeffs_[idx];
		}
		return *this;
	}

	~ComplexPoly() {
		delete[] coeffs_;
		coeffs_ = nullptr;
	}

	Complex& operator[](int idx){
		return coeffs_[idx];
	}

	Complex operator[](int idx) const {
		return coeffs_[idx];
	}

	Complex operator()(Complex val) const {
		Complex pow = val;
		Complex sum = coeffs_[0];
		for (int idx = 1; idx < coeff_length_; ++idx) {
			sum += pow * coeffs_[idx];
			pow *= val;
		}
		return sum;
	}
};