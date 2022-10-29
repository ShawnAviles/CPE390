// 10/27/2022

// need main function to be a valid c++ code
// compile c++ file using g++: g++ -c bench.cc

// use o2 flag for compiler to use optimaization -> do those once your code works
// g++ -o2 -c bench.cc

// used to view the machine instructions of bench.cc
// objdump -d ./a.out

// build all the code with optimization
// g++ -g -o2 bench.cc

// we are using the cgdb debugger
// its a different front end of gdb


#include <iostream>
using namespace std;

int f1a (int a, int b) {
	return a + b;
}

int f1b (int a, int b) {
	return a + b;
}

int f1c (int a, int b) {
	return a + b;
}


// another way to comment out code
#if 0

double f(double x, double y) {
	return x + y;
}

#endif


