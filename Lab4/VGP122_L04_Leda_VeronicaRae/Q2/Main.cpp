/* Write a program to find the factorial of a given number using pointers. */
#include <iostream>
using namespace std;

void factorial(int* x) {
	int fact = 1;
	for (int i = 1; i <= *x; i++) {
		fact *= i; 
	}
	*x = fact; 

}

int main() {
	int num; 
	cout << "Enter a number to calculate its factorial:"; 
	cin >> num; 
	factorial(&num);
	cout << "Factorial: " << num << endl;

	return 0;
}