#include <iostream>
#include <cmath>

using namespace std;

double f1 (double a, double b) {
	return a + b;
}
// 	addsd	%xmm1, %xmm0

double f2 (double a, double b) {
	return a - b;
}
// 	subsd	%xmm1, %xmm0


double f3 (double a, double b) {
	return a * b;
}
// 	mulsd	%xmm1, %xmm0

double f4 (double a, double b) {
	return a / b;
}
// 	divsd	%xmm1, %xmm0

// 	sqrtsd	%xmm1, %xmm0


double f5 (double a) {
	return -a;
}
// xorpd 	LC0(%rip), %xmm0 	#since its a float you just flip the sign bit

double f6 (double a) {
	return abs(a);
}
// andpd	.LC1(%rip), %xmm0 	#and sign bit with 0

double f7 (double a) {
	return sqrt(a);
}
// sqrtps 	