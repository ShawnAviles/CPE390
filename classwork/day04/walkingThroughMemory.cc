// 11/3/2022
#include <iostream>
using namespace std;

void printUninitializedArray () {
	//int a[1000]; // (int = 16 bits = 4 bytes ) * 1000 = 400 bytes
	int a[50];

	for (int i = 0; i < 1000; i++) {
		cout << a[i];
	}
}


uint64_t bench1(uint64_t a[], uint32_t n){
	uint64_t sum = 0;
	for (uint32_t i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum;
}

// we want to unalign the starting address
uint64_t benchUnaligned(uint64_t* a, uint32_t n){
	//a = a + 1; 	// this means point to the next element +8
	// (char*) = (uint8_t*)
	a = (uint64_t*)a + 1;
	uint64_t sum = 0;
	for (uint32_t i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum;
}

// we want to unalign the starting address
// we write so the cache can't optimize the process
uint64_t benchUnalignedWrite(uint64_t* a, uint32_t n){
	// (char*) = (uint8_t*)
	a = (uint64_t*)(uint8_t*)a + 1;
	uint64_t sum = 0;
	for (uint32_t i = 0; i < n; i++) {
		a[i] = 0;
	}
	return 17; // random number
}

int main() {
	// 100mil = 100,000,000 would be too much for the stack
	const uint32_t n = 100000000;
	// uint64_t arr [n]; // stack overflow - asking for too much ram
	uint64_t* arr = new uint64_t[n];
	// cout << bench1(arr, n) << endl;
	cout << benchUnaligned(arr, n) << n;

	// Compiler has builtin memset function (when using optimzatoin) that fixes the unaligned bytes by itself

	delete [] arr;
}