#include <iostream>

int main(){

    long long x = 12345678910111213;
    double y = x;
    long long z = y;

    std::cout << "x = " << x << '\n';
    std::cout << "y = " << y << '\n';
    std::cout << "z = " << z << '\n';

    return 0;
}