#include <iostream>

const double EPS = 1e-6;

int main()
{
	std::cout.precision(32);
    double x = 0.1;
    double y = 1.1 - 1;
    if (std::abs(x-y) < EPS)
        std::cout << "Equal\n";
    else
        std::cout << "NOT Equal\n";
	std::cout << 0.1 << ' ' << 1.1 << ' ' << 1.1 - 1 << '\n';
	return 0;
}