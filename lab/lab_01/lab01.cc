// Shawn Aviles
// 10/28/2022
// Lab 01 - Setting up your environment
#include<iostream>
using namespace std;

double mean(const int a[], int n) {
	// how to get length if was not given: int length  = sizeof(a) / sizeof(a[0]);
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum / n;
}

int main() {
	int a[] = {5, 3, 1, 9};
	double z = mean(a, 4);
	cout << z << '\n';
}

