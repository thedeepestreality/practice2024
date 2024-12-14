#include <iostream>

typedef unsigned long int ulint;
//typedef double(*ud_fun)(double);
using ud_fun = double(*)(double);

double sqr(double val) {
	return val * val;
}

double pow3(double val) {
	return val * val * val;
}

// trapezoid approximate numeric integration
double integrate(
	ud_fun fun,
	double a,
	double b,
	double dx
) {
	double sum = 0.0;
	while (a < b) {
		double right_x = a + dx;
		if (right_x > b) {
			right_x = b;
			dx = right_x - a;
		}
		double square = 0.5 * (fun(a) + fun(a + dx)) * dx;
		sum += square;
		a += dx;
	}
	return sum;
}

int main() {
	//double * ptr;
	//double(*fun)(double);
	//fun = sqr;
	//std::cout << fun(2.0) << '\n';
	//fun = pow3;
	//std::cout << fun(2.0) << '\n';

	double a = 0.0;
	double b = 2.0;
	double dx = 0.01;
	double int_x2_true = (pow3(b) - pow3(a)) / 3;
	double int_x2_approx = integrate(sqr, a, b, dx);

	std::cout << "TRUE int(X^2) = " << int_x2_true << '\n';
	std::cout << "APPR int(X^2) = " << int_x2_approx << '\n';

	double int_x3_true = (sqr(b)*sqr(b) - sqr(a) * sqr(a)) / 4;
	double int_x3_approx = integrate(pow3, a, b, dx);

	std::cout << "TRUE int(X^3) = " << int_x3_true << '\n';
	std::cout << "APPR int(X^3) = " << int_x3_approx << '\n';

	double int_sin_true = -cos(b) + cos(a);
	double int_sin_approx = integrate(sin, a, b, dx);

	std::cout << "TRUE int(sin) = " << int_sin_true << '\n';
	std::cout << "APPR int(sin) = " << int_sin_approx << '\n';

	//ud_fun fun_arr[3] = {sqr, pow3, sin};
	double(*fun_arr[3])(double) = { sqr, pow3, sin };
	for (int idx = 0; idx < 3; ++idx)
		double sum_int = integrate(fun_arr[idx], a, b, dx);

	return 0;
}