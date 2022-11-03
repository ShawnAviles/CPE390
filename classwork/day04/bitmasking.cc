#include <iostream>
// bit masking

// 1011xx10
// set all bits marked xx to one
// use OR
uint8_t set(uint8_t a){
	// 00001100 = 0x0c = mask
	return a | 0x0C;
}

// 0010x1x0
// set all bits marked xx to zero
// use AND
uint8_t clear(uint8_t a){
	// 11110101 = 0xF5;
	return a & 0xF5;
}

// 0010x1x0
// flip
// XOR with 1 to flip
uint8_t clear(uint8_t a){
	// 00001010 = 0xF5;
	return a ^ 0x0A;
}