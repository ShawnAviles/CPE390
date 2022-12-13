#include <iostream>
#include <cmath>

using namespace std;

double mean(int a[], int b) {
	double sum = 0;
	for (int i = 0; i < b; i++) {
		sum += a[i];
	}
	return sum / b;
}

double eval(double arr[], int len, double x) {
	double sum;
	for (int i = 0; i < len; i++) {
		sum += (arr[i]) * pow(x, len - i - 1);
	}
	return sum;
}

void reverse(char s[]) {
	// find the length of the string, last character is '\0'
	int len;
	for (len; s[len] != '\0'; len++)
    ;

    // len = length of the string s
    for (int i = 0; i < len/2; i++) {
		char temp = s[i];
		s[i] = s[len-1-i];
		s[len-1-i] = temp;

		// Without using temp
		// s[i] += s[len-1-i];  // s[i] = sum of both
		// s[len-1-i] = s[i] - s[len-1-i];
		// s[i] = s[i] - s[len-1-i];
    }
}

// Write a function to combine three 8-bit numbers r,g,b into a single color value
// the number should be rrrrrrrrggggggggbbbbbbbb where b is low order bits
uint32_t color(uint32_t r, uint32_t g, uint32_t b) { 
    uint32_t rgb = 0;
    rgb |= (r << 16) | (g << 8) | (b);
    return rgb;
}


int main() {
    int a[] = {1, 2, 3, 4};
    double avg = mean(a, 4); // mean is 2.5 in this example
	cout << "Mean: " << avg << endl;


    double coef[] = {5, -3, 2, 1, 4};
    // evaluate the polynomial 5x^4 - 3x^3 + 2x^2 + x + 4 with x=2.5
    // do this using Horner's form, in a loop:
    // keep multiplying by x and adding each coefficient, like this
    // (but in a loop)
    // ((coef[0] * x + coef[1]) * x + coef[2]) * x + ...
    double evalTest = eval(coef, 5, 2.5);
	cout << "Eval: " << evalTest << endl;

    // in c a string ends with the last character whose ASCII code is '\0'
    // (which is not the digit 0, it's control-@, a non-printable character)
    char s[] = "this is my string\0";
    reverse(s); // s should contain: gnirts ym si siht
	cout << "Reverse: " << s << endl;


    // "hello\0"
    //  hello
    //  // swap the two variables a and b using xor
    // int a = 3, b = 4;
    // a = a ^ b; // 011 XOR 100 = 111 = 7 
    // b = a ^ b; // 111 XOR 100 = 3
    // a = a ^ b;

    // a= 15 - a;
    // if (a == 0)
    //   a = 15;
    // else
    //   a = 0;

    //   reverse the bits of a
    //   1000 ==> 0001
    //   FFT needs bit reversal
    // brev %rcx
	
	uint32_t testColor = color(0x00000011, 0x00000022, 0x00000033);
	cout << testColor  << endl;
}