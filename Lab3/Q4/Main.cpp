/* Write a program that inputs a series of integers and passes them one at a time to
function isEven, which uses the modulus operator to determine whether an integer
is even. The function should take an integer argument and return true if the integer
is even and false otherwise. */

using namespace std;
#include <iostream>

bool isEven(int num) {
	if (num % 2 == 0) {
		return true;
	}
	return false;
}

int main() {
	int number = 1; 
	
	do {
		cout << "Enter an Even Number or 0 to exit: " << endl; 
		cin >> number; 

		if (number != 0) {
			if (isEven(number)) {
				cout << number << " is an Even Number!" << endl;
			}
			else {
				cout << number << " is not an Even Number >:(" << endl;
			}
		}

	} while (number != 0);
	return 0;
}