/* Write a program that asks the user to enter two numbers, obtains the two
numbers from the user and prints the sum, product, difference, and quotient of the
two numbers. */

#include <iostream>
using namespace std; 
float sum(int a, int b) {
	return a + b;
}

float product(int a, int b) {
	return a * b;
}

float difference(int a, int b) {
	return a - b;
}

float quotient(int a,int b) {
	return (1.000* a) / b;
}

int main() {
	float x;
	float y;
	cout << "Enter two numbers:";
	cin >> x;
	cin >> y; 

	cout << "Sum: " << sum(x, y) << endl;
	cout << "Product: " << product(x, y) << endl;
	cout << "Difference: " << difference(x, y) << endl;
	cout << "Quotient: " << quotient(x, y) << endl;
	return 0;
}

