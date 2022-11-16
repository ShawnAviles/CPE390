// Shawn Aviles and Thomas Byrnes
// 11/11/2022

#include <typeinfo>

#include <iostream>
#include <iomanip>
#include <cmath>
#include <bitset>
using namespace std;
int countEvens(int x[], int n);
void addToEach(float x[], int n, float delta);
void range_reverse(int x[], int n, int a, int b);
void compact(int x[], int n, int a, int b);
uint32_t color(uint8_t r, uint8_t g, uint8_t b);
void extractrgb(uint32_t color, uint8_t& r, uint8_t& g, uint8_t& b);
int singleNumber(int x[], int n);


int main() {
    // example for bit operation
    cout << "Question 1-----------------------------------" << endl;
    int arr1[] = {1,2,3,4,5,6,7,8,9,10};
    int res1 = countEvens(arr1, sizeof(arr1) / sizeof(int));
    cout << "# even numbers: " << res1 << endl;

    cout << "Question 2-----------------------------------" << endl;
    float arr2[] = {1.0, 2.0, 3.0, 4.0};
    float delta = 0.5;
    addToEach(arr2, sizeof(arr2) / sizeof(arr2[0]), delta);
    cout << "array after added delta is:" << endl;
    for (auto a: arr2) {
        cout << a << ", ";
    }
    cout << endl;
    
    cout << "Question 3-----------------------------------" << endl;
    int arr3[] = {1,2,3,4,5,6,7,8,9,10};
    range_reverse(arr3, sizeof(arr3) / sizeof(int), 1, 4); // reverse element between index 1 and 4, -> 1,5,4,3,2,6,7,8,9,10
    cout << "array after range reverse is:" << endl;
    for (auto a: arr3) {
        cout << a << ", ";
    }
    cout << endl;
    
    cout << "Question 4-----------------------------------" << endl;
    int arr4[] = {1,2,3,4,5,6,7,8,9,10};
    compact(arr4, sizeof(arr4) / sizeof(int), 1, 4);
    cout << "array after compact is:" << endl; // after compact, array should be 1,6,7,8,9,10,0,0,0,0
    for (auto a: arr4) {
        cout << a << ", ";
    }
    cout << endl;
    
    cout << "Question 5 & 6-------------------------------" << endl;
    uint32_t c = color(0xFF, 0x80, 0x00); // should be 0xFF8000
    cout << hex << c << '\n';
    uint8_t r, g, b;
    extractrgb(c, r, g, b);
    cout <<  "r=" << bitset<8>(r) << " g=" << bitset<8>(g) << " b=" << bitset<8>(b) << endl;

    cout << "Question 7-----------------------------------" << endl;
    int x[] = {1,1,2,3,3,4,4,5,5};
    int res7 =singleNumber(x, sizeof(x) / sizeof(int));
    cout << "the single number is: " << res7 << endl;
    
    return 0;
}

int countEvens(int x[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        // bitmask to check binary 
        if ((x[i] & 1) == 0)  {
            count++;
        }
    }
    return count;
}

void addToEach(float x[], int n, float delta){
    for (int i = 0; i < n; i++) {
        x[i] += delta;
    }
}

void range_reverse(int x[], int n, int a, int b){
    // assumptions: 0 <= a <= b < n
    // approach: use left and right pointers (variables to keep track of indices) that iterates over half of the necessary 
    // range swapping the left and right values
    for (int l = a, r = b; l <= (int)(b - a)/2 + a; l++, r--) {
        int temp = x[l];
        x[l] = x[r];
        x[r] = temp;
    }
}

void compact(int x[], int n, int a, int b){
    // assumptions: 0 <= a <= b < n
    // approach: use left and right pointers (indices) to iterate over the array to set all values after index b to 
    // replace values starting at index a, zero the rest
    int left = a, right = b + 1;
    while (right < n) {
        x[left] = x[right];
        x[right] = 0;
        left++;
        right++;
    }
}

uint32_t color(uint8_t r, uint8_t g, uint8_t b){
    // just combine them into one number
    uint32_t result  = 0;
    result |= r;
    result <<= 8;
    result |= g;
    result <<= 8;
    result |= b;
    return result;
}

// prints wrong by default so the bitmap<8> was called in the main function to display result
void extractrgb(uint32_t color, uint8_t& r, uint8_t& g, uint8_t& b){
    // given color (output of color() function) set appropriate r, g, b values from it)
    b = (uint8_t)(color & 0xFF);; //  color & 0xFF)
    
    color >>= 8;
    g = (uint8_t)(color & 0xFF);

    color >>= 8;
    r = (uint8_t)(color & 0xFF);
}

// approach: use XOR on all values
// added length parameter to the function
int singleNumber(int x[], int n){
    // assuming there are at least three elements 
    for (int i = 0; i < n - 1; i++){
        // always update from left to tright 
        x[i+1] ^= x[i];
    }
    return x[n-1];
}
