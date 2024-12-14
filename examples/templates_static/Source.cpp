#include <iostream>
#include "auxiliar.h"

//#define PI 3.1415
const double PI = 3.1415;
//#define true false

// smoking person abs (defined macro)
//#define abs(val) ((val) < 0 ? -(val) : (val))

// chad abs
// template function
template <typename Type>
Type abs(Type val) {
	return (val < 0 ? -val : val);
}

//void Swap(int* a, int* b) {
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}

//static int x = 0;

//template <class Type>
template <typename Type>
void Swap(Type& a, Type& b) {
	static int N = 0;
	std::cout << ++N << '\n';
	Type tmp = a;
	a = b;
	b = tmp;
}

double filter_moving_avg(double curr) {
	static double prev = 0.0;
	double avg = (curr + prev) / 2;
	prev = curr;
	return avg;
}

//void Swap_int(int a, int b);
//void Swap_double(double a, double b);

template <typename Type1, typename Type2>
double prod(Type1 a, Type2 b) {
	return a * b;
}

int main() {
	//int a = 3;
	//int b = 4;
	///*Swap<int>(a, b);*/
	//Swap(a, b);
	//Swap(a, b);
	//std::cout << a << ' ' << b << '\n';

	//double x = 3.0;
	//double y = 4.0;
	//Swap<double>(x, y);

	//double res = prod(x, y);
	//res = prod(&x, &y);

	std::cout << global << '\n';
	std::cout << global_static << '\n';
	std::cout << dummy() << '\n';

	std::cout << true << '\n';
	//abs(val) (val < 0 ? -val : val)

	std::cout << abs(-1) << '\n';
	//((-1) < 0 ? -(-1) : (-1))

	std::cout << abs(filter_moving_avg(-1)) << '\n';
	//((filter_moving_avg(-1)) < 0 ? -(filter_moving_avg(-1)) : (filter_moving_avg(-1)));

	return 0;
}
