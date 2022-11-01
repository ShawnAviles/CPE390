#include <iostream>
using namespace std;

int f(int b);

int main() {
	uint8_t a = 57; 			// 00111001
	uint8_t b = 0x2B | ~0x2B; 	// 0xFF
	uint8_t c = ~0x2B; 			// 11010100
	uint8_t d = 0x1C | 0x31; 	// 0001 1100 | 0011 0001 = 0011 1101

	// logical AND (&&) completely different than bitwise AND (&)
	// could lead to different values if used
	uint8_t e = a & b;			// 0

	// short-circuiting
	if (a < 2 && f(b) > 3) { 	// logical AND is short-circuited (a < 2 == FALSE)
		// do it
	}
	if (a > 3 || f(b) > 5){		// logical OR is short circuited (a > 3 == TRUE)
		// do it
	} 

	// XOR
	// A XOR 1 = NOT A
	uint8_t f = a ^ b;			// 0011 1001 ^ 1111 1111 == 1100 0110

	// right shift
	uint8_t g = 3 << 2;			// equalivalent to 3*4
	// left shift
	uint8_t h = 17 >> 1; 		// 17 / 2 = 8 (divides by 2 but truncates it still)
	uint8_t i = 19 >> 3 << 2;	// 0001 0011 (19) --> 0000 0010 (2) --> 0000 1000 (8)

	uint8_t j = 18 / 8 * 4; 	// = 8
	uint64_t m = 10 / 3 / 4;	// = 0
	double x = 10 / 3 / 4;		// = 0.0 
	double y = 10 / 4 * 2; 		// = 4.0
	// if there are differing datatypes, the computer promotes the smaller datatype to the same 
	// as the larger one and computers - "type promotion"
	double z = 10 / 4.0 * 2; 	

	// if optimizer is on then it will acknoeldge this as a rotate left move, else it computers the 3 bitwise
	j = (j << 2) | (j >> 6);	// claim this is ROL by 2 
}