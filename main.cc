#include <iostream>

int f(int a, int c);

int main() {
	int z = f(2,3);
	std::cout << 'z' << '\n';
}

// run using MakeFile
// run command: make
// purpose - allows you to not have to rebuild everything when you compile the code

// now look at the assembly
// command: cdgb bench

// step into machine language instruction
// command: si
// stands for 'Step Instruction'

// go to next machine language instruction
// command: ni
// stands for 'Next Instruction'