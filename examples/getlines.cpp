#include <iostream>
#include <string>

int main() {
	char str[32];
	std::cin >> str;
	std::cout << "Input: \"" << str << '\"' << std::endl;
	std::cin.getline(str, 31);
	std::cout << "Input: \"" << str << '\"' << std::endl;
	std::cin.get(str, 31);
	std::cout << "Input: \"" << str << '\"' << std::endl;
	std::cin.getline(str, 31);
	std::cout << "Input: \"" << str << '\"' << std::endl;

	std::string stdstr;
	std::getline(std::cin, stdstr);

	return 0;
}