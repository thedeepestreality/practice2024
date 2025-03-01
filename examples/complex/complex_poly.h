#pragma once
#include "complex.h"
#include <initializer_list>

class ComplexPoly {
private:
	Complex* coeffs_;
	size_t coeff_length_;
public:
	ComplexPoly() {
		coeffs_ = new Complex[1];
		coeff_length_ = 1;
	}

	ComplexPoly(Complex* coeffs, size_t length) {
		coeffs_ = new Complex[length];
		coeff_length_ = length;
		for (size_t idx = 0; idx < length; ++idx)
			coeffs_[idx] = coeffs[idx];
	}

	ComplexPoly(const ComplexPoly& right) : ComplexPoly(right.coeffs_, right.coeff_length_) {}

	Complex& operator=(const ComplexPoly& right) {
		if (this == &right) {
			delete[] coeffs_;
			coeff_length_ = right.coeff_length_;
			coeffs_ = new Complex[coeff_length_];
			for (size_t idx = 0; idx < coeff_length_; ++idx)
				coeffs_[idx] = right.coeffs_[idx];
		}
	}

	~ComplexPoly() {
		delete[] coeffs_;
		coeffs_ = nullptr;
	}
};