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
    // compile using g++ -O2
    /*
    	your assembler goes here
    
    
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
	return num1 * num1 + num2 * num2;
}

int factorial(int n){
	if (n ==  0 || n == 1) return 1;
	return n * factorial(n - 1);
}

