#include <iostream>
using namespace std;
int* p;

int main() {
	constexpr int n = 800000000;
	p = new int[n];

	for (int j = 0; j < 2; j++){
		for (int i = j; i < n; i+=2) {
			p[i] = i;
		}
	}
	cout << p[n-3];
	delete [] p;
}