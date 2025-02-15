#include "IntDynArray.h"
#include <utility>

void IntDynArray::init(int sz) {
	m_size = sz;
	m_data = new int[sz];
	m_ptr = 0;
}

void IntDynArray::clean() {
	delete[] m_data;
}

// default constructor
IntDynArray::IntDynArray() {
	m_size = 0;
	m_ptr = 0;
	m_data = new int[0];
}

// parametrized constructor
IntDynArray::IntDynArray(int sz) {
	init(sz);
}

IntDynArray::IntDynArray(int* arr, int sz)
{
	init(sz);
	for (int idx = 0; idx < sz; ++idx)
		m_data[idx] = arr[idx];
	m_ptr = m_size;
}

// destructor
IntDynArray::~IntDynArray() {
	clean();
}

void IntDynArray::push_back(int val) {
	if (m_ptr >= m_size) {
		// reallocate data
		const int new_size = std::max(2 * m_size, 1);
		int* new_arr = new int[new_size];
		for (int idx = 0; idx < m_size; ++idx)
			new_arr[idx] = m_data[idx];
		delete[] m_data;
		m_data = new_arr;
		m_size = new_size;
	}
	m_data[m_ptr] = val;
	++m_ptr;
}

void IntDynArray::set(int idx, int val){
	if (idx < 0 || idx >= m_ptr)
		throw "index is out of array range";
	m_data[idx] = val;
}

int IntDynArray::get(int idx) const {
	if (idx < 0 || idx >= m_ptr)
		throw "index is out of array range";
	// this is valid in const method
	//m_data[idx] = 5; //*(m_data+idx) = 5;
	// this is invalid in const method
	//m_data = new int[3];
	return m_data[idx];
}

int IntDynArray::getSize() const
{
	return m_size;
}
