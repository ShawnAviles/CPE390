// 10/27/2022

// need main function to be a valid c++ code
// compile c++ file using g++: g++ -c bench.cc

// use o2 flag for compiler to use optimaization -> do those once your code works
// g++ -o2 -c bench.cc

// i think this is what's used to view the different files bench.cc is compiled to
// objdump -d bench.cc

// build all the code with optimization
// g++ -g -o2 bench.cc

// we are using the cgdb debugger
// its a different front end of gdb


#include <iostream>
using namespace std;


int f(int a, int b); // function prototype

int main() {
	int z = f(2,3);
	cout << 'z' << '\n';
}

int f (int a, int b) {
	return a + b;
}




// another way to comment out code
#if 0

double f(double x, double y) {
	return x + y;
}

#endif


