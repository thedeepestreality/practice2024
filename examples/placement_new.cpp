#include <iostream>

struct Dummy {
	Dummy() {
		std::cout << "Default constructor!\n";
	}
	Dummy(int val) {
		std::cout << "Parameterized!\n";
	}
};

int main() {
	const int SZ = 3;

	// this will call default constructor SZ times
	Dummy* arr = new Dummy[SZ];
	// this will call destructor SZ times and free memory
	delete[] arr;

	// global operator new
	// constructors are not called, only raw memory allocated
	void* raw_arr = ::operator new(SZ * sizeof(Dummy));
	Dummy* tmp = reinterpret_cast<Dummy*>(raw_arr);
	for (int idx = 0; idx < SZ; ++idx)
		// now we need to explicitly call to constructors
		// using placement new
		new(tmp + idx) Dummy(idx);

	for (int idx = 0; idx < SZ; ++idx)
		// explicit call to destructor
		tmp[idx].~Dummy();
	// global operator delete only deallocates memory
	// without calling to the destructors
	::operator delete[](tmp);

	return 0;
}
