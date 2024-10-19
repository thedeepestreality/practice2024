#include <iostream>

int main()
{
	int size;
	std::cout << "Enter size: ";
	std::cin >> size;
	double half = (size + 1) / 2.0;
	for (int row = 1; row <= size; ++row)
	{
		int stars = 2 * (half - std::abs(half - row)) - 1;
		for (int col = 0; col < (size + stars) / 2; ++col)
			std::cout << (col < (size - stars) / 2 ? " " : "*");
		std::cout << std::endl;
	}
	return 0;
}