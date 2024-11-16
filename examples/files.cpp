#include <iostream>
#include <fstream>

int main() {
	std::ifstream in("in.txt");
	if (!in) {
		std::cout << "Failed to open input file!\n";
		return 1;
	}

	std::ofstream out("C:\\repos\\spbu\\out.txt");
	//std::ofstream out("/home/sevostyanov/out.txt");
	if (!out) {
		std::cout << "Failed to open output file!\n";
		return 2;
	}

	while (!in.eof()) {
		char c = in.get();
		if (c >= 'A' && c <= 'Z')
			c -= 'A' - 'a';
		out << c;
	}

	out.close();
	in.close();
	return 0;
}