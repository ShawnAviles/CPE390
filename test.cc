// 25/10/2022
#include <iostream>

// windows - msys2 to run g++ (https://www.msys2.org/)
// max - old intel can use msys2 but new applie silicon have it by default

// int = whatever is fastest on your specific machine
// int >= 16 bits
// 2 ^ 16 = 65536
// value for int: -32768 ... 0 1 .. 32767
// int = 32 bits -> -2.1 billion ... +2.1 billion

// using g++ compiler in mac compiles code to a.out file while windows g++ compiler creates a.exe file

uint64_t add (uint64_t a, uint64_t b){
	return a + b;
}

uint64_t add2 (uint64_t a, uint64_t b); // function prototype

int f (int a) {
	return a*2;
}

// slower to run add() than 2+3 since its gotta go there and comeback when the function is called 
int main() {
	std::cout << f(3) << '\n';

	// optimizer in c++ would auto add these constants together before compiliation because it removes extra lines of assembly from needing to be run
	// no computation is done for: uint64_t c = 2 + 3;

	uint64_t c = 2 + 3; 	// constant expressions are evaluated at compile time
	uint64_t d = add(2,3);	// inline functions are replaced by code
	uint64_t e = add2(2,3);	// invalid function call
}

// invalid function declaration without function protortype before main()
uint64_t add2 (uint64_t a, uint64_t b){
	return a + b;
}
