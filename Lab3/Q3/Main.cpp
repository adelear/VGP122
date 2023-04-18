/* Define a function hypotenuse that calculates the hypotenuse of a right triangle
when the other two sides are given. The function should take two double arguments
and return the hypotenuse as a double. Use this function in a program to determine
the hypotenuse for each of the triangles shown below. 

Triangle	Side 1		Side 2
1			3.0			4.0
2			5.0			12.0
3			8.0			15.0 */


// c^2 = a^2 +b^2;

using namespace std; 
#include <iostream>
#include <cmath> 
#include <iomanip>

double calculateHyp(double x, double y) {
	double c = 0; 
	c = sqrt((pow(x,2)) + (pow(y,2)));
	return c;
}

int main() {
	double triangleLengths[3][2]; 

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cout << "Enter the length of side " << j+1 << " of Triangle " << i+1 << ": ";
			cin >> triangleLengths[i][j];

		}
	}
	for (int i = 0; i < 3; i++) {
		cout << "\nHypoteneuse of triangle " << i+1 << ": " << fixed << setprecision(1) << calculateHyp(triangleLengths[i][0], triangleLengths[i][1]) << endl;
	}
	return 0;
}