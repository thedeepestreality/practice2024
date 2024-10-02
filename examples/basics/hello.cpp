#include <iostream>

int main(){
	std::cout << "hello world\n";
	int x = 0;
	int y = 0;
	std::cout << "input x and y: ";
	std::cin >> x >> y;
	std::cout << "x = " << x << ", y = " << y << '\n';
	std::cout << "x + y = " << x + y << '\n';
	return 0;
}
