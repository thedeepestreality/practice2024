#include <iostream>
#include <ctime>

int main() {
	// basic arrays
	//int arr[] = { 1,2,3 }; //size will be automatically evaluated

	// will not work, only const sizes are allowed
	//int sz = 3;
	//int arr[sz] = {};

	const int SZ = 3;
	int arr[SZ] = {}; // array with zeros
	std::cout << "array size = ";
	std::cout << sizeof(arr) / sizeof(arr[0]) << '\n';
	for (int i = 0; i < SZ; ++i) {
		arr[i] = i*i;
	}

	for (int i = 0; i < SZ; ++i) {
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';

	int arr2[SZ] = {};
	//arr2 = arr; //error: forbidden to assign arrays

	// 2D array
	int matrix[3][2] = {
		{0, 1},
		{1, 1},
		{1, 0}
	};

	// 3D array
	int tensor[2][3][4] = {
		{
			{0,1,2,3},
			{0,2,4,6},
			{0,3,6,9},
		},
		{
			{3,2,1,0},
			{6,4,2,0},
			{9,6,3,0},
		},
	};

	// find maximum
	const int SZ3 = 10;
	int arr3[SZ3] = { -5, 2, 6, 15, -300, 100500, 8, -42, 0, 25 };
	int max_val = arr3[0];
	for (int i = 0; i < SZ3; ++i)
		if (arr3[i] > max_val)
			max_val = arr3[i];
	std::cout << "Maximum = " << max_val << '\n';
	
	// random values
	srand(time(nullptr));
	int a = -200;
	int b = 300;
	int val = rand()%(b-a+1) + a; //[a, b] -> (x%(b-a+1)) + a;
	std::cout << val << '\n';

	return 0;
}