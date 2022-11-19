// Shawn Aviles and Thomas Byrnes
// Lab 02
// 11/4/2022

#include <iostream>
#include <iomanip>
#include <cmath>
#include <bitset>
using namespace std;

// part 1:
float sum_forward(int n);
float sum_backward(int n);
// part 2:
void double_each(int a[], int n);
float mean(float x[], int n);
// part 3:
uint64_t setbits5_9(uint64_t a);
uint64_t clearlow4(uint64_t a);
// part 4:
uint64_t pack(uint32_t x[], uint32_t len, uint64_t out[]);


int main() {
    // part 1:--------------------------------------------------------------
    cout << "part 1 output:" << endl;
    float q1_ans_1 = sum_forward(100);
    float q1_ans_2 = sum_backward(100);
    cout << setprecision(8)<< q1_ans_1 << endl;
    cout << setprecision(8) << q1_ans_2 << endl;

    // part 2:--------------------------------------------------------------
    cout << "part 2 output:" << endl;
    float x[] = {10, 20, 30, 40, 50, 60};
    constexpr int n = sizeof(x)/sizeof(float);
    cout << mean(x, n) << endl; // should print 35
    float y[] = {1.0, 2.0, 3.0, 4.0};
    cout << mean(y, sizeof(y)/sizeof(float)) << endl; // should print 2.5
    int z[] = {10, 20, 30, 40, 50, 60};
    int z_len = sizeof(z)/sizeof(int);
    double_each(z, z_len);
    for (int i = 0; i < z_len; i++) {
        cout << z[i] << ",";
    }
    cout << endl;

    // part 3:--------------------------------------------------------------
    cout << "part 3 output:" << endl;
    cout << hex << clearlow4(0x9ACEULL) << endl;
    uint64_t a4 = setbits5_9(0xFACEB001);
    cout << hex << a4 << endl;
    
    // part 4:--------------------------------------------------------------
    cout << "part 4 output:" << endl;
    const uint32_t input_size = 1026;
        uint32_t* p = new uint32_t[input_size];
        for (uint32_t i = 0; i < input_size; i++)
            p[i] = i & 3; // write numbers from 0..3 into each array element
    // allocate enough 64-bit numbers to hold the output
    uint64_t* out =  new uint64_t[(input_size+31) / 32];
    int out_len = pack(p, input_size, out);
    cout << "the len of output array should be:   " << out_len << endl;
    cout << "the output array after packed should be:  " << endl;
    for (uint32_t i = 0; i < out_len; i++) {
        cout << out[i] << ',';
    }
    cout << endl;
	
    return 0;
}

// part 1:
float sum_forward(int n) {
	float result = 0;
	for (int i = 1; i <= n; i++) {
		result += (1.0 / i);
	}
	return result;
}
float sum_backward(int n) {
	float result = 0;
	for (int i = 100; i > 0; i--) {
		result += (1.0 / i);
	}
	return result;
}

// part 2:
float mean(float x[], int n){ // returns sum not mean
	float sum = 0;
	for (int i = 0; i < n; i++) {
        sum += x[i];
    }
    return sum/(float)n;
}
void double_each(int a[], int n){
	for (int i = 0; i < n; i++) {
        a[i] += a[i];
    }
}

// part 3:
uint64_t setbits5_9(uint64_t a) {
    uint64_t bitmask = 0b1111100000;
    return a | bitmask;
} 

uint64_t clearlow4(uint64_t a){
	uint64_t bitmask = 0xFFFFFFFFFFFFFFF0;
	return a & bitmask;
}

// part 4:
uint64_t pack(uint32_t x[], uint32_t len, uint64_t out[]){
    uint64_t temp = 0;
    int outIndex = 0;

    for (int i = 0; i < len; i++) {
        temp += x[i];
        temp <<= 2;

        if ((i + 1) % 32 == 0) {
            // update out array with packed 32 numbers (64 bits)
            out[outIndex] = temp;
            outIndex++;

            // reset temp to 0
            temp = 0;
        }
    }

    // we return the outIndex by itself since its +1 of the last filled index of the out array 
	return outIndex;
}
