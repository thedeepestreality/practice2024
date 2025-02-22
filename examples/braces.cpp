#include <iostream>
#include <cassert>

bool validBraces(const char* str) {
	int counter = 0;
	while (*str != 0) {
		if (*str == '(')
			++counter;
		else
			--counter;
		if (counter < 0)
			return false;
		++str;
	}
	return (counter == 0);
}

int main() {
	// ok tests
	assert(validBraces(""));
	assert(validBraces("()"));
	assert(validBraces("()()"));
	assert(validBraces("(())"));
	assert(validBraces("()(())"));
	// fail tests
	assert(!validBraces("("));
	assert(!validBraces(")"));
	assert(!validBraces(")("));
	assert(!validBraces("()("));
	assert(!validBraces("(()"));
	assert(!validBraces("())"));
	std::cout << "All tests passed!\n";
	return 0;
}
