#include <iostream>

int main(int argc, char* argv[]) {
	for (int idx = argc - 1; idx > 0; --idx) {
		std::cout << idx << " | ";
		int count = atoi(argv[idx]);
		//int count = strtol(argv[idx], nullptr, 10);
		//std::cout << "errno = " << errno << '\n';
		for (int num = 0; num < count; ++num)
			std::cout << '*';
		std::cout << ' ' << argv[idx] << '\n';
	}

	//std::ifstream in(argv[1]);

	//// compute sum of arguments
	//int sum = 0;
	//for (int idx = 1; idx < argc; ++idx)
	//	sum += atoi(argv[idx]);
	//std::cout << "Sum = " << sum << '\n';
	return 0;
}