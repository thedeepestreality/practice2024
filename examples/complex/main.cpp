#include <iostream>
#include "complex.h"
#include "complex_poly.h"

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
	////Pain* ptr;
	////{
	////	int x = 2;
	////	Pain* pain = new Pain(x);
	////	ptr = pain;
	////	x = 3;
	////}
	////std::cout << (*ptr).calculate() << '\n';
	////delete ptr;

	////StaticExample::static_x = 4;
	////std::cout << StaticExample::static_x << '\n';

	////StaticExample var;
	////var.static_x = 5;

	//Complex val1(1.0, 2.0);
	//(std::cout << val1) << '\n';

	//Complex val2(0.5, 0.1);
	//Complex val3(2.0, 1.0);
	//(val1 += val2) += val3;

	//val3 = 1.0 + val2; // works only without `explicit` constructor
	////val3 = Complex(1.0) + val2;

	//std::cout << val3 << '\n';

	ComplexPoly poly0();
	Complex coeffs1[] = {Complex(1), Complex(2), Complex(1) };
	
	ComplexPoly poly1(coeffs1, 3);
	
	ComplexPoly poly2(poly1);	// 1 -- Copy constructor
	ComplexPoly poly3 = poly1;  // 2 -- Copy constructor
	ComplexPoly poly4;			// 3 -- Default constructor +
	poly4 = poly1;				// assignment

	std::cout << poly2[1] << '\n';
	poly2[1] = Complex(3, 0);

	const ComplexPoly poly_const = poly2;
	std::cout << poly_const[1] << '\n';

	Complex res = poly2(Complex(3));
	std::cout << "res = " << res << '\n';

	//poly2, poly1 <=> operator,(poly2, poly1);

	return 0;
}