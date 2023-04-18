/* Write an application that finds the smallest of several integers. Assume that the
first value read specifies the number of values to input from the user. */

#include <iostream>
using namespace std;

int main() {
	int totalNum, counter = 0, tempNum, smallestNum = 999999;


	cout << "Enter number of integers to input" << endl;
	cin >> totalNum;

	cout << "Enter " << totalNum << " numbers" << endl;

	while (counter!=totalNum) {

		cin >> tempNum;
		counter++;
		if (tempNum < smallestNum) {
			smallestNum = tempNum;
		}
	}

	cout << "\nThe smallest number is " << smallestNum << endl;

	return 0;
}