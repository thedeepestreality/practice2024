#include <iostream>
#include <cmath>

int main()
{
    double x;
    double eps;
    std::cout << "input x: ";
    std::cin >> x;
    std::cout << "input eps: ";
    std::cin >> eps;
    double sum = 1.0;
    double tmp = x;
    int n = 1;
    while (tmp >= eps){
        sum += tmp;
        ++n;
        tmp *= x/n;
    }
    std::cout << "res = " << sum << '\n';
    std::cout << "exp = " << exp(x) << '\n';
    return 0;
}