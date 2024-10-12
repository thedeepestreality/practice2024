#include <iostream>
#include <cmath>

int main()
{
    double x = std::sqrt(-1);
    if (x == x)
        std::cout << "Equal\n";
    else if (x != x)
        std::cout << "NOT Equal\n";
    return 0;
}