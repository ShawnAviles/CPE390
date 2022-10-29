// homework 1
// complete functions below
// read chapter 2 and 3 
#include <iostream>
using namespace std;


void countPowers(int iterations);
int sumsquares(int num1, int num2);
int factorial(int n);

int main() {
    // 1. write a function that counts powers of 2
    // use uint32_t
    // multiply each time 1, 2, 4, 8, 16, ...
    // repeat 33 times
	cout << "\nNumber 1: \n";
	countPowers(33);
	
	
	// 2. write a function to sum the square between a and b
	cout << "\nNumber 2: \n";
    cout << sumsquares(3, 42) << endl; // 3*3 + 4*4 + ...
	
    // show the assembler 
    // compile using: 		g++ -g -o2 homework01.cc
	// display assembler: 	objdump -d ./a.out
    /*	your assembler goes here:
		
		0000000000000c88 <_Z10sumsquaresii>:
		c88:	d10083ff 	sub	sp, sp, #0x20
		c8c:	b9000fe0 	str	w0, [sp, #12]
		c90:	b9000be1 	str	w1, [sp, #8]
		c94:	b9001bff 	str	wzr, [sp, #24]
		c98:	b9400fe0 	ldr	w0, [sp, #12]
		c9c:	b9001fe0 	str	w0, [sp, #28]
		ca0:	14000009 	b	cc4 <_Z10sumsquaresii+0x3c>
		ca4:	b9401fe0 	ldr	w0, [sp, #28]
		ca8:	1b007c00 	mul	w0, w0, w0
		cac:	b9401be1 	ldr	w1, [sp, #24]
		cb0:	0b000020 	add	w0, w1, w0
		cb4:	b9001be0 	str	w0, [sp, #24]
		cb8:	b9401fe0 	ldr	w0, [sp, #28]
		cbc:	11000400 	add	w0, w0, #0x1
		cc0:	b9001fe0 	str	w0, [sp, #28]
		cc4:	b9401fe1 	ldr	w1, [sp, #28]
		cc8:	b9400be0 	ldr	w0, [sp, #8]
		ccc:	6b00003f 	cmp	w1, w0
		cd0:	54fffead 	b.le	ca4 <_Z10sumsquaresii+0x1c>
		cd4:	b9401be0 	ldr	w0, [sp, #24]
		cd8:	910083ff 	add	sp, sp, #0x20
		cdc:	d65f03c0 	ret
    */


	// 3. write function?
	// n = 1 to 25
   	// compute factorial(n)
	cout << "\nNumber 3: \n";
	for (int n = 1; n <= 25; n++) {
		cout << "factorial of " << n << " is " << factorial(n) << endl;
	}
}

void countPowers(int iterations) {
	uint32_t num1 = 1;
	cout << "Iteration 1: " << num1 << endl;
	for (int i = 1; i < iterations; i++) {
		num1 <<= 1;
		cout << "Iteration " << i + 1 << ": " << num1 << endl;
	}
}

int sumsquares(int num1, int num2) {
	int sum = 0;
	for (int i = num1; i <= num2; i++) {
		sum += i * i;
	}
	return sum;
}

int factorial(int n){
	if (n ==  0 || n == 1) return 1;
	return n * factorial(n - 1);
}

