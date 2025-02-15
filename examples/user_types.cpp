#include <iostream>

enum class Direction {
	Left,
	Right,
	Up,
	Down
};

// dir == 0 -> left
// dir == 1 -> right
// dir == 2 -> up
// dir == 3 -> down
//void handleGamepadMovePress(int dir){
//	switch (dir) {
//		case 0:
//			//move left
//			break;
//		case 1:
//			//move right
//			break;
//	}
//}

void handleGamepadMovePress(Direction dir) {
	switch (dir) {
	case Direction::Left:
		// move left;
		break;
	case Direction::Right:
		// move right;
		break;
	}
}

enum class DayOfWeek {
	Monday = 25,
	Tuesday = 42,
	Wednesday = 3,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

void printDayOfWeek(DayOfWeek day) {
	switch (day) {
	case DayOfWeek::Monday:
		std::cout << "Monday\n";
		break;
	}
}

// dir == true -> width
// dir == false -> depth
//void switchToggle(bool onoff)

double dist(double x0, double y0, double x1, double y1) {
	return std::sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
}

struct Point {
	double x;
	double y;
};

double dist(Point p0, Point p1)
{
	return std::sqrt((p1.x - p0.x) * (p1.x - p0.x) + (p1.y - p0.y) * (p1.y - p0.y));
}

struct UintBytes {
	unsigned char byte1;
	unsigned char byte2;
	unsigned char byte3;
	unsigned char byte4;
};

struct Byte {
	unsigned char bit1 : 1;
	unsigned char bit2 : 1;
	unsigned char bit3 : 1;
	unsigned char bit4 : 1;
	unsigned char bit5 : 1;
	unsigned char bit6 : 1;
	unsigned char bit7 : 1;
	unsigned char bit8 : 1;
};

// deprecate memory alignment
#pragma pack(1)
struct AlignTest {
	int var1;
	double var2;
};
#pragma pop

union ParamValue {
	char c;
	int i;
	double d;
};

union YetAnotherBytes {
	unsigned int var;
	unsigned char bytes[4];
};

enum class ParamType {
	Int,
	Double,
	Char
};

struct Param {
	ParamType type;
	ParamValue val;
};

struct Arr3 {
	int arr[3];
};

struct Arr256{
	int arr[256];
	int size;
};

int main(){
	handleGamepadMovePress(Direction::Left);
	printDayOfWeek((DayOfWeek)6);

	Point p = { 1.0, 2.0 };
	p.x = 1.0;
	p.y = 2.0;

	Point* ptr = &p;
	(*ptr).x = 5.5;
	ptr->x = 5.6;

	unsigned int uvar = 257;
	unsigned char* uvar_bytes = (unsigned char*)&uvar;
	// uvar_bytes[0] // == uvar % 256
	std::cout << (int)uvar_bytes[0] << std::endl;
	std::cout << (int)uvar_bytes[1] << std::endl;

	UintBytes* bytes = (UintBytes*) & uvar;
	std::cout << (int)bytes->byte1 << std::endl;
	std::cout << (int)bytes->byte2 << std::endl;

	std::cout << sizeof(Byte) << std::endl;
	std::cout << "-------\n";
	unsigned char var = 5;
	Byte* var_bits = (Byte*)&var;
	std::cout << (int)var_bits->bit1 << std::endl;
	std::cout << (int)var_bits->bit2 << std::endl;
	std::cout << (int)var_bits->bit3 << std::endl;

	std::cout << "------\n";
	std::cout << sizeof(AlignTest) << std::endl;

	// anonymous union
	union {
		int val_666;
		unsigned char bytes_666[4];
	};
	val_666 = 4;
	bytes_666[0] = 1;

	//int arr1[] = { 1,2,3 }; // int * const arr1;
	//int arr2[] = { 4,5,6 };
	//arr1 = arr2;

	Arr3 arr1 = { 1,2,3 };
	Arr3 arr2 = { 4,5,6 };
	arr2 = arr1;

	return 0;
}
