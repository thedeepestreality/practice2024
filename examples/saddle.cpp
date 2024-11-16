#include <iostream>

const int ROWS = 3;
const int COLS = 3;

void saddle(
	int arr[ROWS][COLS],
	int rows,
	int cols,
	int& r_out,
	int& c_out) 
{
	r_out = -1;
	c_out = -1;
	for (int r = 0; r < rows; ++r) {
		// find minimum in current row
		int min_val = arr[r][0];
		int min_col = 0;
		for (int c = 0; c < cols; ++c)
			if (arr[r][c] < min_val) {
				min_val = arr[r][c];
				min_col = c;
			}
		// find maximum in min_col column
		int max_val = arr[0][min_col];
		int max_row = 0;
		for (int rc = 0; rc < rows; ++rc)
			if (arr[rc][min_col] > max_val) {
				max_val = arr[rc][min_col];
				max_row = rc;
			}
		if (max_row == r) {
			r_out = r;
			c_out = min_col;
			return;
		}
	}
}

int main() {
	int arr[ROWS][COLS] = {
		{1, 2, 3},
		{5, 3, 4},
		{3, 1, 8}
	};
	for (int r = 0; r < ROWS; ++r) {
		for (int c = 0; c < COLS; ++c)
			std::cout << arr[r][c] << ' ';
		std::cout << '\n';
	}
	int r;
	int c;
	saddle(arr, ROWS, COLS, r, c);
	std::cout << '\n' << r << ' ' << c << '\n';
	return 0;
}