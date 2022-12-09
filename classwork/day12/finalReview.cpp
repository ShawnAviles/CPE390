#include <iostream>
using namespace std;

void reverse(char s[]) {
	int len;

	// get length of string
	for (len = 0; s[len] != '\0'; len++);

	// loop over and swap characters
	for (int i = 0; i < len/2; i++) {
		// swap (using temp)
		char temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = temp;

		// swap (without using temp)
		s[i] += s[len-1-i]; 				// s[i] = sum of both
		s[len-1-i] = s[i] - s[len-1-i];		
		s[i] = s[i] - s[len-1-i];

		// swap (two variables using )
		int a = 3, b = 4;
		a = a ^ b;	// 011 XOR 111 = 111 = 7
		b = a ^ b;	// 111 XOR 100 (7 ^ 4) = 3
		a = a ^ b; 	// 7 ^ 3 = 4
	}
}

int main() {

	// reverse string without being given length
	// every stirng in c++ ends in 000 ASCII code or '\0' character
	char s[] = "this is my string";
	reverse(s);




}



