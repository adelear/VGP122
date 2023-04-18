/* Implement the following integer functions:
a. Function celsius returns the Celsius equivalent of a Fahrenheit temperature.
b. Function fahrenheit returns the Fahrenheit equivalent of a Celsius
temperature.
c. Use these functions to write a program that prints charts showing the
Fahrenheit equivalents of all Celsius temperatures from 0 to 100 degrees, and
the Celsius equivalents of all Fahrenheit temperatures from 32 to 212 degrees.

Print the outputs in a neat tabular format that minimizes the number of lines of
output while remaining readable. */
#include <iostream>
#include <iomanip>
using namespace std;



float fToCelsius(float fahrenheit) {
	fahrenheit = (fahrenheit - 32) * 5 / 9;
	return floor(fahrenheit * 100 + 0.5) / 100;
}

float cToFahrenheit(float celsius) {
	celsius = (celsius * 9 / 5) + 32;
	return floor(celsius * 100 + 0.5) / 100;
}

int main() {
	cout << "Celsius | Fahrenheit     Fahrenheit | Celsius" << endl;

	for (int c = 0, f = 32; c <= 100 && f <= 212; c++, f++) {
		float fahrenheit = cToFahrenheit(c);
		float celsius = fToCelsius(f);

		//cout << fixed << setprecision(2) << c << "       |      " << fahrenheit << "        " << f << "      | "      << celsius << endl;
		cout << fixed << setprecision(2) << setw(7) << c << " | " << setw(10) << fahrenheit << "     " << setw(7) << f << " | " << setw(7) << celsius << endl;
	} 

	return 0;

}