/* Factorials are used frequently in probability problems. The factorial of a
positive integer n (written n! and pronounced “n factorial”) is equal to the product
of the positive integers from 1 to n. Write an application that calculates the
factorials of 1 through 20. Use type long. Display the results in tabular format. */

#include <iostream>
using namespace std;

int main() {
	long long totalNum, factorial=1,counter=1; 

	cout << "Enter a number: "; 
	cin >> totalNum;

	while (counter <= totalNum) {
		//Starting from the lowest number, multiply factorial with counter until counter reaches the initialized number
		//Counter increases by 1 each time (1*1, then 1*2, 2*3, 6*4, 24*5)
		factorial *= counter; 
		counter++;
		cout << factorial << endl;
	}

	cout << "\nThe factorial of " << totalNum << " is " << factorial << endl;

	return 0;
}
