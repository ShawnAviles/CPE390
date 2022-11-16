#include <iostream>

using namespace std;

// order of registers that would be used for uint64_t: rcx, rdx, rsi

// by convention	%rcx			%rdx
uint64_t sum(uint64_t a[], uint64_t len) {
	uint64_t s = 0;		// if optimized it would probably be %rsi, %rax
	for (uint64_t i = 0; i < len; i++) {
		s += a[i];
	}
	return s; // returns to %rax
}
/*

_Z3sumPyy:
.LFB1859:
	...
	testq 	%rdx, %rdx 				# checks to make sure that the value exists, should not try to iterate over it if it DNE 
	je		.L6
	leaq 	(%rdx, %rdx, 8), %rdx	# have to keep in mind datatype and how large each element is (i.e. each element is 8 bytes)
	xorl 	%eax, %eax
	...
.L5:
	addq	(%rcx), %rax
	addq	$8, %rcx
	cmpq	%rdx, %rcx
	jnw		.L5
	ret
	...


*/