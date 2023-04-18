/* Use a one-dimensional array to solve the following problem. Read in 20 numbers,
each of which is between 10 and 100, inclusive. As each number is read, validate it
and store it in the array only if it isn’t a duplicate of a number already read. After
reading all the values, display only the unique values that the user entered. Provide
for the “worst case” in which all 20 numbers are different. Use the smallest
possible array to solve this problem. */
#include <iostream> 
using namespace std; 


int main() {
	int numArray[20] = { 0 }; //Initialize array with 0. Before, it printed out a weird number at the beginning of the list
	
	int arraySize = 1;
	

	while (arraySize < 20) {
		cout << "Enter a number " << arraySize << "/20 between 10 and 100. No duplicates: ";
		int num;
		cin >> num;

		//1. has to be between 10 and 100 
		if (num >= 10 && num <= 100){

			bool duplicateFound = false;

			for (int i = 0; i < arraySize; i++) {
				//2. the number does not already exist
				if (num == numArray[i]) {
					duplicateFound = true;
					break;
				}
			}

			if (duplicateFound) {
				cout << "\nInvalid Number. Duplicate Number.\n" << endl;
			}
			else {
				numArray[arraySize] = num;
				arraySize+=1;
			}
		
		}
		else {
			cout << "\nInvalid Number. Not between 10 and 100.\n" << endl;
		}
		
	}
	
	//Printing out the list of numbers

	cout << "\nThe list of numbers is:";
	for (int i = 1; i < 20; i++) {
		if (i == 1) {
			cout << numArray[1];
		}
		else {
			cout << "," << numArray[i];
		}
	}
	return 0;
}