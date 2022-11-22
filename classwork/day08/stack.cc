#include <iostream>

void add_one(uint64_t x[]);

void copy(uint64_t a[], uint32_t len) {
	uint64_t arr[10];
	for (uint64_t i = 0; i < len; i++){
		arr[i] = a[i];
	}
	add_one(arr);
}

int main() {
	int x; 		// uintialized -> random bits
	uint64_t a[10]; 	// random garbage by default (same)
	copy(a, 5);
}

void add_one(uint64_t x[]){
	for (int i = 0; i < 10; i++) {
		x[i]++;
	}
}

// look at it in debugger
/*
gdb a
b main
run
layout asm
layout reg

*/

// look at it at assembler
/*
g++ -o2 -S stack.cc
*/

// Notes
/*
- registers with "_sp" format stand for Stack Pointer
- order of registers that are used: rcx, rdx, rsi, rdi

*/

