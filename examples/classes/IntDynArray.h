#pragma once
class IntDynArray {
private:
	int* m_data;
	int m_size;
	int m_ptr;

	void init(int sz);
	void clean();
public:
	// default constructor
	IntDynArray();
	// parametrized constructor
	IntDynArray(int sz);
	// parametrized constructor
	IntDynArray(int* arr, int sz);
	// destructor
	~IntDynArray();

	void push_back(int val);
	void set(int idx, int val);
	int get(int idx) const;
	int getSize() const;
};
