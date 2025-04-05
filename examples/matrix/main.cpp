#include <iostream>
#include <cassert>
#include "Matrix.h"

int main() {
	Matrix m1(2, 2);
	m1.at(0, 0) = 1;
	m1.at(0, 1) = 2;
	m1.at(1, 0) = 3;
	m1.at(1, 1) = 4;
	Matrix m2 = m1;
	assert(m2.rows() == m1.rows() && m2.cols() == m1.cols());
	for (int row = 0; row < 2; ++row)
		for (int col = 0; col < 2; ++col)
			assert(m2.at(row, col) == m1.at(row, col));
	m1 += m1;
	for (int row = 0; row < 2; ++row)
		for (int col = 0; col < 2; ++col)
			assert(m1.at(row, col) == 2 * m2.at(row, col));
	Matrix m3 = m1 + m2;
	for (int row = 0; row < 2; ++row)
		for (int col = 0; col < 2; ++col)
			assert(m3.at(row, col) == 3 * m2.at(row, col));
	std::cout << "All tests passed!\n";
	std::cout << m3;
	return 0;
}
