#include <iostream>
#include "IntDynArray.h"

struct S {
	// public by default
	int val;
};

class C {
	// private by default
	int val;
};



//void initDynArray(IntDynArray* arr, int size) {
//	arr->m_size = size;
//	arr->m_data = new int[size];
//	arr->m_ptr = 0;
//}
//
//void deleteDynArray(IntDynArray* arr) {
//	delete[] arr->m_data;
//}

int main()
{
	const int ARR_SIZE = 10;
	int arr[ARR_SIZE] = { 0,1,2,3,4,5,6,7,8,9 };
	/*IntDynArray arr1(ARR_SIZE);*/
	IntDynArray arr1(arr, ARR_SIZE);
	//for (int idx = 0; idx < arr1.getSize(); ++idx)
	//	arr1.push_back(idx);
	try {
		arr1.set(2, 2 * arr1.get(2));

		for (int idx = 0; idx < arr1.getSize(); ++idx)
			std::cout << arr1.get(idx) << '\n';
	}
	catch (const char* err_msg) {
		std::cout << "caucht exception: " << err_msg << '\n';
	}

	//arr1.init(ARR_SIZE);
	//arr1.clean();
	

	IntDynArray arr2;
	arr2.push_back(2);
	// this is memory leak
	//arr1 = arr2;

	//const IntDynArray const_arr(ARR_SIZE);
	//const_arr.get(2);


	// PROBLEM 1: DATA CONSISTENCY
	// Solved with private fields
	//arr1.m_size = 20;
	//for (int idx = 0; idx < arr1.m_size; ++idx)
	//	std::cout << arr1.m_data[idx] << std::endl;

	//initDynArray(&arr1, ARR_SIZE);
	// 
	//arr1.size = ARR_SIZE;
	//arr1.data = new int[ARR_SIZE];
	//arr1.ptr = 0;

	//delete[] arr1.data;
	//deleteDynArray(&arr1);

	//arr1.clean();
	//S s;
	//s.val = 1;
	//C c;
	//c.val = 1;
	return 0;
}
