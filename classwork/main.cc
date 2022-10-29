#include <iostream>
using namespace std;

#if 0
int f(int a, int c);

int main() {
	int z = f(2,3);
	std::cout << 'z' << '\n';
}
#endif

int main () {
	int a = 12 * 4; // constant expression
	int x;
	cin >> x;
	int b = x / 2;

	// pow(2,8) = 256
	// pow(2,16) = 65536
	// pow(2,32) = 42... billion
	// pow(2,64) = 1.8 quadrillion

	// bit shift right - zero comes in from left
	uint32_t c = x >> 1;

	// divding -> right shift
	// divide by 10 in decimal
	// 983 / 10 = 98 (shift number to the right)

	// divide binary number by 2 
	// 0010 / 2 = 0001 (shift number to the right)

	// mulitply -> left shift
	uint32_t d = x * 32; // turns into: x << 5

	// compute x / 125128951
	// compute x / 256 turns into c >> 8

	// int8_t (signed) -> -128... + 127
	int8_t e = 3;

	/*
	bits	signed		unsigned
	000 = 	0			0
	001 =	1			1
	010 =	2			2
	011 =	3			3
	100 = 	-4			4
	101 = 	-3			5
	110 = 	-2			6
	111 = 	=1			7
	*/

	// we want to divide by 2
	// e = 3 		-> 0000 0011
	e = e >> 1; // shorthand is e >>= 1 (right shift e by 1 and set e equal to the new value)
	// e = 3 >> 1 	-> 0000 0001

	e = -3;
	// 2s compliment
	// 0000 0011
	// invert very bit 1111 1100
	// add 1 1111 1101 = -3
	e >>= 1;
	// signed right shift copies the sign bit
	// arithmetic shift
	// 1111 1110

	// 4 machine language instruction
	// unsigned >> n	LSR		Logical Shift Right
	// unsigned << n	LSL		Logical Shift Left
	// signed >> n		ASR		Arithmetic Shift Right
	// signed << n		ASL		Arithmetic Shift Left



}



// run using MakeFile
// run command: make
// purpose - allows you to not have to rebuild everything when you compile the code

// now look at the assembly
// command: cdgb bench

// step into machine language instruction
// command: si
// stands for 'Step Instruction'

// go to next machine language instruction
// command: ni
// stands for 'Next Instruction'