#include <iostream>
#include <fstream>

// ch from [0,15]
char digitToHex(char ch) {
	if (ch < 10)
		return '0' + ch;
	return 'A' + ch - 10;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "No filename provided\n";
		return -1;
	}
	std::ifstream in(argv[1], std::ios::binary);
	if (!in) {
		std::cout << "Failed to open file\n";
		return -2;
	}
	// line size
	const int SZ = 16;
	char buf[SZ];
	while (!in.eof()) {
		in.read(buf, SZ);
		int fact_size = in.gcount();
		for (int idx = 0; idx < fact_size; ++idx) {
			/*std::cout << (int)buf[idx] << ' ';*/
			char msb = buf[idx] / 16;
			char lsb = buf[idx] % 16;
			std::cout << digitToHex(msb) << digitToHex(lsb) << ' ';
		}
		std::cout << '\n';
	}
	return 0;
}