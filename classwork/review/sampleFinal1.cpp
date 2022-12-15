#include <iostream>
#include <cmath>

using namespace std;


/* Sample Final 1 - Question 2: Implement the following C++ functions in Intel assembler: */
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
	for (len; s[len] != '\0'; len++);

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
/* Sample Final 1 - End of Question 2 */



/* Sample Final 1 - Question 3: Implement the following C++ functions in Intel assembler: */
//              %rcx        %rdx      
uint64_t f(uint64_t a, uint64_t b) {
    return (a+b)*(a-b);
}
/*
    xorq    %rax, %rax              # clear rax
    leaq    (%rcx, %rdx), %rax      # rax = rcx + rdx = a + b
    subq    %rdx, %rcx              # rcx = rcx - rdx = a - b
    imulq   %rcx, %rax              # rax = rax * rcx = (a+b)*(a-b)
    ret                             # return value in rax
*/

//          %rcx        %rdx
bool mask(uint64_t a, uint64_t b) {
    return a & b == b;
}
/* 
    andq    %rdx, %rcx              # a & b
    cmp     %rcx, %rdx              # (a & b) == rdx
    je     .EQUAL
    movq    $0, %ax                # if not equal, then return 0
    ret                            # return value in ax (we are returning a boolean in this case which is 16 bits)
.EQUAL
    movq    $1, %ax                # if equal, then return 1
    ret                            # return value in ax (we are returning a boolean in this case which is 16 bits)
*/

//                  %rax        %rcx        (not sure if he would let us choose which registers)
uint64_t toggle(uint64_t a, uint64_t mask) {
    return a ^ mask;
}
/*
    xorq    %rcx, %rax              # rax = rax ^ rcx
    ret                             # return value in rax
*/

// sum the numbers from a to b inclusive
//                  %rcx        %rdx
uint64_t toggle(uint64_t a, uint64_t b) {
    uint64_t sum = 0;
    for (uint64_t i = a; i <= b; i++)
      sum += i;
    return sum;
}
/*
    xorq    %rax, %rax              # clear rax, rax = 0 
    cmp     %rcx, %rdx              # check if we have hit the limit already
    jge     .END                    # (jump if rdx >= rcx) to end
.LOOP
    addq    %rcx, %rax              # rax = rax + rcx
    addq    $1, %rcx                # rcx = rcx + 1
    cmp     %rdx, %rcx              # compare rcx and rdx
    jl      .LOOP                   # jump if less - jump if rcx < rdx
    ret                             # return value in rax
.END
    ret
*/
/* Sample Final 1 - Question 3 End */


/* Sample Final 1 - Question 4: Optimization Show how the optimizer changes the following code to make it faster.
    ASSUMPTION: I think this is just the optimized c++ code representation*/
uint64_t f1(uint64_t a, uint64_t b) {
    uint64_t x = 3 + 4;             // x = 7;                           (simplifies constants)
    return a * 2 + b * 16 + x;      // return (a << 1) + (b << 4) + x;  (simplifies power of two multiplication to bit shift left)    
}

uint64_t f2(uint64_t a, uint64_t b) {
    return a / 2 + b % 4;           // return (a >> 1) + (b & 0x3);     (does bitwise operations)
}

uint64_t f3(uint64_t a) {
    return (a << 3) | (a >> 61);    // return (a >> 58);                (simplifies bitshift) ?
}

uint64_t f4(uint64_t a) {
    return a * 9;                   // return a << 3 + a;               (this would take advantge of singe instruction lea)                
}
/* Sample Final 1 - Question 4 End. */


/* Sample Final 1 - Question 4: Optimization Show how the optimizer changes the following code to make it faster.
    ASSUMPTION: assembly optimization */
//              %rcx        %rdx
uint64_t f1(uint64_t a, uint64_t b) {
    uint64_t x = 3 + 4;
    return a * 2 + b * 16 + x;
}
/*
    leaq    ($3, $4), %rax
    shlq    $1, %rcx
    shlq    $4, %rdx
    addq    %rcx, %rdx
    addq    %rdx, %rax
    ret 
*/

//              %rcx        %rdx
uint64_t f2(uint64_t a, uint64_t b) {
    return a / 2 + b % 4;
}
/*
    shlq    $1, %rcx
    andq    $3, %rdx
    addq    %rcx, %rdx
    movq    %rdx, %rax
    ret 
*/

//              %rcx
uint64_t f3(uint64_t a) {
    return (a << 3) | (a >> 61);
}
/*  (I don't see how this is an optimization though)
    movq    %rcx, %rax
    shlq    $3, %rcx
    shrq    $61, %rax
    orq     %rcx, %rax
    ret
*/

//              %rcx 
uint64_t f4(uint64_t a) {
    return a * 9;                   // return a << 3 + a;               (this would take advantge of singe instruction lea)                
}
/*
    leaq    (%rcx, %rcx, 8), %rax  
*/
/* Sample Final 1 - Question 4 End. */
