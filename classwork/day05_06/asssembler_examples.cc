#include <iostream>
using namespace std;

uint64_t add(uint64_t a, uint64_t b) {
	return a + b;
}
/*
		.globl	_Z3addyy
_Z3addyy:
	leaq	(%rcx,%rdx), %rax
	ret
*/


uint64_t sub(uint64_t a, uint64_t b) {
	return a + b;
}
/*
	.globl	_Z3subyy
_Z3subyy:
	movq	%rcx, %rax // rax = a
	subq	%rdx, %rax // rax = a-b
	ret
*/

//                   rcx          rdx
uint64_t prod(uint64_t a, uint64_t b) {
	uint64_t p = 1;
	for (uint64_t i = a; i <= b; i++)
		p *= i;
	return p;
}
/*
	.globl	_Z4prodyy
_Z4prodyy:
	movl	$1,   %eax  // p = 1 (move long 1 to register eax, eax is the low half of rax)
	cmpq	%rcx, %rdx  // if a > b... (compare quad)
	jb	.L5           	// skip everything
.L7:                	// if you are here a <= b
	imulq	%rcx, %rax  // prod = 1*a
	addq	$1,   %rcx  // a++
	cmpq	%rcx, %rdx  // is a <= b?
	jnb	.L7           	// go back and do it again
.L5:
	ret
*/
// Notes: never use blank loop as a timer, the compiler's optimizer would remove it and a better cpu would run it faster
// so its inconsistent
// rcx, rdx, rsi, rdi are registers that are used by functions so don't touch them
// hcfb (hang catch fire burn) - break cpu, fabled to exist


// g++ -o2 -S nameOfFile.cc (creates a name.s file with the assembly)
// XOR with itself, sets it to 0
// less instructions does not directly mean that its faster than more instructions
// less instrucitons use less power compared to the same type but more instructions
// pipelining is what is needed to optimize assembly code


uint64_t max(uint64_t a, uint64_t b) {
	if (a > b)
		return a;
	return b;
}
/*
	.globl	_Z3maxyy
_Z3maxyy:
  	cmpq	%rdx, %rcx    	// compare a and b
	movq	%rdx, %rax    	// rax = b
	cmovnb	%rcx, %rax  	// if a was bigger, rax = a
	ret
*/
// return the answer to rax by default
// takes 3 clock cycles in total, all are 1 clock cycle here
// mulq - 3 clock cycles
// divq - 15 clock cycles or something
// movq, xor1... - 1 clock cycle (simple stuff)
// NOPXXX - manual delay waiting for pipeline to catch up

// Informal Hw - find all the jump commands in assembly, about 16 of them
// "Intel Branch Jump Conditions" - http://unixwiz.net/techtips/x86-jumps.html 
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

uint64_t complicated(uint64_t a, uint64_t b, uint64_t c, uint64_t d) {
	if (b % 2 != 1) // checks if even
		d += 3;
	if (c % 4 == 2)
		a -= 4;
	return (a * (b + 1) + c * d * (b - 3)) * (a + 2);
}

// Notes: 
/*
// checking if number is even
mov 	%rcx, 	%r9
andq	%1,		%r9 	// r9 rightmost bit = 1
compq 	%0,		$r9
jg ...

// equivalent to 
tstq 	$1, 	%rdx 	// test 
jg ...
addq 	$3, 	$rdi
*/

// when code compiled with g++ -march=native -o2
// -m "architecture = native" - compile the most efficiently for MY computer don't compile to run on every computer
// first four registers are default, anything over that is being taken on the stack

// leal ("load effective address")