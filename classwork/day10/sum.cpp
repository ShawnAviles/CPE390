#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	// sum numbers 1/1 + 1/2 + 1/3 + ... + 1/100
	float sum = 0;
	for (float i = 1; i <= 100; i++) {
		sum += 1/i;	// type-promotion, or: sum += 1.0/i 
	}
	//cout << "Sum1: " << sum << endl;

	float sum2 = 0;
	for (float i = 100; i >= 1; i--) {
		sum2 += 1/i;
	}

	cout << setprecision(7);
	cout << sum << "\t" << sum2 << endl;
	cout << (sum - sum2) << endl;

}