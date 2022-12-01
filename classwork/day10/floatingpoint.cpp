#include <iostream>
#include <iomanip>
#include <cmath>
#include <numbers>

using namespace std;
using namespace std::numbers; // part of c++ 20


int main() {
	uint32_t a; // 4 bytes, range = 0 to 2^32 or 0 to ~4.2 billion

	// floats have bits allocated to decide the sign, number, and e
	float f = 1.2345678f; // 32-bits, single precision, IEEE 754 (standardized)
	f = 12.345678;
	f = 123.45678;
	f = 1.2345678e+23;
	f = -1.234e+38;
	f = 1.234e-38;
	/*
		we have 1's and 0's with binary point in the middle -> i.e. 110101010101.11010101
		things floats keep track of:
			sign = +/-
			exponent (where to put the binary digits)
			mantissa (the digits)
		
		1.0 = 1
		10.0 = 2
		101.0 = 5
		.1 = 1/2
		.01 = 1/4
		.001 = 1/8
		3/8 = 0.375 (in decimal) = 0.011

		1/2 = 0.5
		1/3 = 0.3333333333333

		1/10 = 0.1 (in decimal) = 0.00011001100110011...
	*/
	double d = 1.23456789012345;
	d = 1.234e+308;
	d = 1.234e-308;
	long double e;
	// quad precision is coming
	// half precision is here 

	// setprecision(12) would be 
	cout << setprecision(8);
	for (float x = 0; x < 10; x+=0.1f) {
		cout << x << " \n";
	}
	/* 
	Its not exact:
	0 
	0.1 
	0.2 
	0.30000001 
	0.40000001 
	0.5 
	0.60000002 
	0.70000005 
	0.80000007 
	0.9000001 
	1.0000001 
	1.1000001 
	1.2000002 
	1.3000002 
	1.4000002 
	1.5000002 
	1.6000003 
	1.7000003 
	1.8000003 
	1.9000003 
	2.0000002 
	2.1000001 
	2.2 
	2.3 
	2.3999999 
	2.4999998 
	2.5999997 
	2.6999996 
	2.7999995 
	2.8999994 
	2.9999993 
	3.0999992 
	3.1999991 
	3.299999 
	3.3999989 
	3.4999988 
	3.5999987 
	3.6999986 
	3.7999985 
	3.8999984 
	3.9999983 
	4.0999985 
	4.1999984 
	4.2999983 
	4.3999982 
	4.4999981 
	4.599998 
	4.6999979 
	4.7999978 
	4.8999977 
	4.9999976 
	5.0999975 
	5.1999974 
	5.2999973 
	5.3999972 
	5.4999971 
	5.599997 
	5.6999969 
	5.7999969 
	5.8999968 
	5.9999967 
	6.0999966 
	6.1999965 
	6.2999964 
	6.3999963 
	6.4999962 
	6.5999961 
	6.699996 
	6.7999959 
	6.8999958 
	6.9999957 
	7.0999956 
	7.1999955 
	7.2999954 
	7.3999953 
	7.4999952 
	7.5999951 
	7.699995 
	7.7999949 
	7.8999949 
	7.9999948 
	8.0999947 
	8.199995 
	8.2999954 
	8.3999958 
	8.4999962 
	8.5999966 
	8.6999969 
	8.7999973 
	8.8999977 
	8.9999981 
	9.0999985 
	9.1999989 
	9.2999992 
	9.3999996 
	9.5 
	9.6000004 
	9.7000008 
	9.8000011 
	9.9000015 
	*/

	// this would be an infinite loop bc x would never be exactly 10 becuase of round off error
	// don't use != or == with float its meaningless
	// for (float x = 0; x != 10; x += 0.1f) {
	// 	cout << x << " \n";
	// }

	float x = 0.0;
	float y = 1.0 / x; 
	cout << y << endl; // inf
	y *= 2;
	cout << y << endl; // inf
	cout << sqrt(y) << endl; // inf

	double z = -3 / x;
	cout << z << endl; // -inf

	cout << (y + z) << endl; // inf + -inf = nan (Not a Number) -> WE DON'T KNOW

	cout << sin(0) << endl; // 0
	cout << sin(2*pi) << endl;
	cout << sin(y) << endl; // sing(inf) = NaN

	/*
	What are the properties
	a + b == b + a (commutative) -> always works
	(a + b) + c != a + (b + c) (associative) -> does not work with floating point
	
	a = 1.23 
	b = .069
	c = .059

	i.e. we have a 3-digit computer
	(a + b) + c
	1.23 
	 .069
	======
	1.29
	 .059
	======
	1.34

	a + (b + c)
	 .069
	 .059
	======
	 ,128
	1.23
	======
	1.35

	Thus, (a + b) + c != a + (b + c)
	*/

}
