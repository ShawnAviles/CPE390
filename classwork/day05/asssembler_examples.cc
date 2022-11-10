#include <iostream>
using namespace std;

uint64_t add(uint64_t a, uint64_t b) {
	return a + b;
}

uint64_t sub(uint64_t a, uint64_t b) {
	return a + b;
}

uint64_t prod(uint64_t a, uint64_t b) {
	uint64_t p = 1;
	for (uint64_t i = a; i <= b; i++)
		p *= i;
	return p;
}

uint64_t max(uint64_t a, uint64_t b) {
	if (a > b)
		return a;
	return b;
}

// Informal Hw - find all the jump commands in assembly, about 16 of them
// "Intel Branch Jump Conditions" - http://unixwiz.net/techtips/x86-jumps.html 
// 
/*

JO		Jump if overflow
JNO		Jump if not overflow
JS		Jump if sign
JNS		Jump if not sign
JE		Jump if equal
JZ		Jump if zero
JNE		Jump if not equal
JNZ		Jump if not zero
JB		Jump if below
JNAE	Jump if not above or equal
JC		Jump if carry
JNB		Jump if not below
JAE		Jump if above or equal
JNC		Jump if not carry
JBE		Jump if below or equal
JNA		Jump if not above
JA		Jump if above
JNBE	Jump if not below or equal
JL		Jump if less
JNGE	Jump if not greater or equal
JGE		Jump if greater or equal
JNL		Jump if not less
JLE		Jump if less or equal
JNG		Jump if not greater
JG		Jump if greater
JNLE	Jump if not less or equal
JP		Jump if parity
JPE		Jump if parity even
JNP		Jump if not parity
JPO		Jump if parity odd
JCXZ	Jump if %CX register is 0
JECXZ	Jump if %ECX register is 0

*/