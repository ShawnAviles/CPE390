#include <iostream>
using namespace std;

double f(double a, double b);
double sum(double arr[], int len);
//double mean()


main () {
	cout << f(3.0, 4.0); // (a+b)*(a-b)

	double x[] = {1, 2, 3, 5.5};	// 5.5 = 101.1 (binary)

	cout << sum(x, 4) << '\n';

	// cout << mean(x,4) << endl;
}