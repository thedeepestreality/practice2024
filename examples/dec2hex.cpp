#include <iostream>

int main(){
	std::cout << "input dec number: ";
	int val;
	std::cin >> val;
	const int base = 16;

	int deg = 1;
	int val_copy = val;
	while (val_copy != 0) {
		val_copy /= base;
		deg *= base;
	}
	deg /= base;

	while (val != 0) {
		int digit = val / deg;
		// pretty ugly, not recommended
		// std::cout << (char)(digit + (digit < 10 ? '0' : 'A' - 10));
		char out_char;
		if (digit < 10)
			out_char = digit + '0';
		else
			out_char = digit + 'A' - 10;
		std::cout << out_char;
		val %= deg;
		deg /= base;
	}
	std::cout << '\n';
	// only for visual studio runs
	system("pause");
	return 0;
}
