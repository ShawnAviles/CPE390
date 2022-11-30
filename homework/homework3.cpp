// testing code for written assignment
#include <iostream>
using namespace std;

int main() {
	int a = 3 / 2 + 4; 
	uint64_t b = 10 / 3 * 4;
	uint64_t c = 10 / 3 / 4;
	uint64_t d = 10 / 2.5 * 2;
	double e = 5 / 2;
	double f = 5 / 2 * 3;
	uint64_t g = 1000000 * 1000000; 
	bool b1 = g == 1000000000000ULL; 
	uint64_t h = 1000000;
	h *= 1000000;
	

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;
	cout << "d: " << d << endl;
	cout << "e: " << e << endl;
	cout << "f: " << f << endl;
	cout << "b1: " << b1 << endl;
	cout << "h: " << h << endl;
}

