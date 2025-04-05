#pragma once

#include <iostream>

// Rule of five:
// 1 Copy constructor
// 2 Move constructor
// 3 Assignment by copy
// 4 Assignment by move
// 5 Destructor

// only integer type
class Matrix {
private:
	int** m_data;
	int m_rows;
	int m_cols;
public:
	Matrix(int rows = 1, int cols = 1);
	// copy constructor
	Matrix(const Matrix& val);
	// sometimes it is possible to use like this
	// same efficiency
	// Matrix(Matrix val) { std::move(val); }
	// move constructor
	Matrix(Matrix&& val);

	// assignment by copy
	Matrix& operator=(const Matrix& val);
	// assignment by move
	Matrix& operator=(Matrix&& val);

	Matrix& operator+=(const Matrix& val);

	int& at(int row, int col);

	int rows() const;
	int cols() const;

	~Matrix();
};

Matrix operator+(const Matrix& left, const Matrix& right);
std::ostream& operator<<(std::ostream& out, const Matrix& val);
