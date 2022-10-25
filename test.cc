#include <iostream>

// windows - mysys2 to run g++ 
// max - old intel use mysys2 but new applie silicon have it by default

// int = whatever is fastest on your machine
// int >= 16 bits
// 2 ^ 16 = 65536
// -32768 ... 0 1 .. 32767
// int = 32 bits -> -2.1 billion ... +2.1 billion

int f (int a) {
	return a*2;
}


int main() {
	std::cout << f(3) << '\n';
}