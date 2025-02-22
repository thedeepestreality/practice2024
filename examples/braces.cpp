#include <iostream>
#include <cassert>

//bool f(const char* s){
//	int c=0;
//	while(*s){
//		c+=*s=='('?1:-1;
//		if(c<0)return 0;
//		++s;
//	}return!c;}

bool f(char*s){int c=0;for(;*s&&c>=0;c-=2**s++-81);return!c;}

int main() {
	// ok tests
	assert(f((char*)""));
	assert(f((char*)"()"));
	assert(f((char*)"()()"));
	assert(f((char*)"(())"));
	assert(f((char*)"()(())"));
	// fail tests
	assert(!f((char*)"("));
	assert(!f((char*)")"));
	assert(!f((char*)")("));
	assert(!f((char*)"()("));
	assert(!f((char*)"(()"));
	assert(!f((char*)"())"));
	std::cout << "All tests passed!\n";
	return 0;
}
