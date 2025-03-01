#include <iostream>
#include "complex.h"

class Pain {
private:
	const int& val_;
public:
	Pain(const int& val) : val_(val) {

	}
	int calculate() {
		return val_ * val_;
	}
};

struct StaticExample {
	int local_x;
	static int static_x;
	static const int const_static = 2;
};

int StaticExample::static_x = 2;

int main() {
	//Pain* ptr;
	//{
	//	int x = 2;
	//	Pain* pain = new Pain(x);
	//	ptr = pain;
	//	x = 3;
	//}
	//std::cout << (*ptr).calculate() << '\n';
	//delete ptr;

	//StaticExample::static_x = 4;
	//std::cout << StaticExample::static_x << '\n';

	//StaticExample var;
	//var.static_x = 5;

	Complex val1(1.0, 2.0);
	(std::cout << val1) << '\n';

	Complex val2(0.5, 0.1);
	Complex val3(2.0, 1.0);
	(val1 += val2) += val3;

	val3 = 1.0 + val2; // works only without `explicit` constructor
	//val3 = Complex(1.0) + val2;

	std::cout << val3 << '\n';

	

	return 0;
}