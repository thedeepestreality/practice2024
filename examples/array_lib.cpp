#include <iostream>

int** create2DArray(int rows, int cols) {
	int** arr = new int*[rows];
	for (int idx = 0; idx < rows; ++idx)
		arr[idx] = new int[cols];
	return arr;
}

void delete2DArray(int** arr, int rows) {
	for (int idx = 0; idx < rows; ++idx)
		delete[] arr[idx];
	delete[] arr;
}

void print2DArray(int** arr, int rows, int cols) {
	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < cols; ++c)
			std::cout << arr[r][c] << '\t';
		std::cout << '\n';
	}
	std::cout << '\n';
}

void fillConsecutive(int** arr, int rows, int cols) {
	for (int r = 0; r < rows; ++r)
		for (int c = 0; c < cols; ++c)
			arr[r][c] = r * cols + c;
}

int main() {
	int rows;
	int cols;
	std::cout << "Input rows cols: ";
	std::cin >> rows >> cols;
	int** arr = create2DArray(rows, cols);
	fillConsecutive(arr, rows, cols);
	print2DArray(arr, rows, cols);
	delete2DArray(arr, rows);
	return 0;
}