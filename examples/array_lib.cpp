#include <iostream>
#include <fstream>

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

void printToFile(
	const char* file_name,
	int** arr,
	size_t rows,
	size_t cols
) {
	std::ofstream out(file_name);
	if (!out)
		throw "Failed to open output file!\n";

	out << rows << ' ' << cols << '\n';
	for (int r = 0; r < rows; ++r)
	{
		for (int c = 0; c < cols; ++c)
			out << arr[r][c] << ' ';
		out << '\n';
	}
}

int** readFromFile(const char* file_name, int& rows, int& cols) {
	std::ifstream in(file_name);
	if (!in)
		throw "Failed to open input file!\n";

	in >> rows >> cols;
	int** arr = create2DArray(rows, cols);
	for (int r = 0; r < rows; ++r)
		for (int c = 0; c < cols; ++c)
			in >> arr[r][c];
	return arr;
}

int dummy(int n) {
	if (n == 42)
		return 0;
	return -1;
}

void dummyException(int n) {
	if (n != 42)
		throw -1;
}

void platypus() {
	std::cout << "meow\n";
	dummyException(41);
	std::cout << "purr\n";
}

void bar() {
	std::cout << "bar() started\n";
	try {
		platypus();
	}
	catch (int err) {
		std::cout << "platypus error\n";
	}
	std::cout << "bar() finished\n";
}

void foo() {
	std::cout << "foo() started\n";
	bar();
	std::cout << "foo() finished\n";
}

int main() {
	int rows;
	int cols;
	std::cout << "Input rows cols: ";
	std::cin >> rows >> cols;
	int** arr = create2DArray(rows, cols);
	fillConsecutive(arr, rows, cols);
	print2DArray(arr, rows, cols);
	const char* file_name = "C:\\repos\\spbu\\out.txt";
	try {
		printToFile(file_name, arr, rows, cols);
		int file_rows;
		int file_cols;
		int** arr_from_file = readFromFile(file_name, file_rows, file_cols);
		print2DArray(arr_from_file, file_rows, file_cols);
		delete2DArray(arr_from_file, file_rows);
	}
	catch (const char* err_str) {
		std::cout << "somebody trown exception: " << err_str;
	}
	delete2DArray(arr, rows);

	// Case with return error handling
	//int res = foo();
	//if (res < 0) {
	//	std::cout << "Failed to open file " << file_name << '\n';
	//	return 1;
	//}

	//try {
	//	foo();
	//}
	//catch (int err) {
	//	std::cout << "exception if foo(): " << err << '\n';
	//}
	
	return 0;
}