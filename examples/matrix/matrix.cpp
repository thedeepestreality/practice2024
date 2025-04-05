#include "Matrix.h"

Matrix::~Matrix() {
	// check if object is already dead
	if (m_data == nullptr)
		return;
	// clear memory
	for (int r = 0; r < m_rows; ++r)
		delete[] m_data[r];
	delete[] m_data;
	// in case of the second destructor call
	m_data = nullptr;
	m_rows = 0;
	m_cols = 0;
}

int Matrix::rows() const {
	return m_rows;
}

int Matrix::cols() const {
	return m_cols;
}

Matrix::Matrix(int rows, int cols) :m_cols(cols), 
									m_rows(rows), 
									m_data(new int*[rows])
{
	for (int row = 0; row < m_rows; ++row) {
		m_data[row] = new int[m_cols];
	}
}

Matrix::Matrix(const Matrix& val) : Matrix(val.m_rows, val.m_cols)
{
	for (int row = 0; row < m_rows; ++row)
		for (int col = 0; col < m_cols; ++col)
			m_data[row][col] = val.m_data[row][col];
}

Matrix& Matrix::operator=(const Matrix& val) {
	if (this == &val)
		return *this;
	// clear memory
	if (m_data != nullptr){
		for (int r = 0; r < m_rows; ++r)
			delete[] m_data[r];
		delete[] m_data;
	}
	m_rows = val.m_rows;
	m_cols = val.m_cols;
	m_data = new int* [m_rows];
	for (int row = 0; row < m_rows; ++row){
		m_data[row] = new int[m_cols];
		for (int col = 0; col < m_cols; ++col)
			m_data[row][col] = val.m_data[row][col];
	}
	return *this;
}

void Matrix::swap(Matrix&& val) noexcept {
	std::swap(val.m_data, m_data);
	std::swap(val.m_rows, m_rows);
	std::swap(val.m_cols, m_cols);
}

Matrix::Matrix(Matrix&& val) noexcept : m_data(nullptr), m_rows(0), m_cols(0) {
	swap(std::move(val));
}

Matrix& Matrix::operator=(Matrix&& val) noexcept {
	swap(std::move(val));
	return *this;
}

Matrix& Matrix::operator+=(const Matrix& val) {
	if (m_rows != val.m_rows || m_cols != val.m_cols)
		throw "wrong sizes";
	for (int row = 0; row < m_rows; ++row)
		for (int col = 0; col < m_cols; ++col)
			m_data[row][col] += val.m_data[row][col];
	return *this;
}

Matrix operator+(const Matrix& left, const Matrix& right) {
	Matrix res = left;
	res += right;
	return res;
}

int& Matrix::at(int row, int col) {
	return m_data[row][col];
}

int Matrix::at(int row, int col) const {
	return m_data[row][col];
}

std::ostream& operator<<(std::ostream& out, const Matrix& val) {
	for (int row = 0; row < val.rows(); ++row) {
		for (int col = 0; col < val.cols(); ++col)
			out << val.at(row, col) << " ";
		out << '\n';
	}
	return out;
}
