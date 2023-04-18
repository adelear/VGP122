/* Function floor can be used to round a number to a specific decimal place. The
statement y = floor(x * 10 + 0.5) / 10; rounds x to the tenths position (the
first position to the right of the decimal point). The statement y = floor(x * 100
+ 0.5) / 100; rounds x to the hundredths position (the second position to the
right of the decimal point). Write a program that defines four functions to round a
number x in various ways:
a. roundToInteger(number)
b. roundToTenths(number)
c. roundToHundredths(number)
d. roundToThousandths(number)

For each value read, your program should print the original value, the number
rounded to the nearest integer, the number rounded to the nearest tenth, the
number rounded to the nearest hundredth and the number rounded to the nearest
thousandth. */

#include <iostream>
#include <cmath>
using namespace std;

int roundToInteger(float number) {
	return round(number);	
}

float roundToTenths(float number) {
	return number = floor(number * 10 + 0.5) / 10;
}

float roundToHundredths(float number) {
	return number = floor(number * 100 + 0.5) / 100;
}

float roundToThousandths(float number) {
	return number = floor(number * 1000 + 0.5) / 1000;
}



int main() {
	float num;
	cout << "Enter a number: ";
	cin >> num; 

	cout << "\nOriginal value: " << num << endl;  
	cout << "Rounded to Nearest Integer: " << roundToInteger(num) << endl;
	cout << "Rounded to Nearest Tenth: " << roundToTenths(num) << endl;
	cout << "Rounded to Nearest Hundredth: " << roundToHundredths(num) << endl;
	cout << "Rounded to Nearest Thousandth: " << roundToThousandths(num) << endl;

}



