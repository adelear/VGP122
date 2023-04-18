/* A parking garage charges a $20.00 minimum fee to park for up to three hours. The
garage charges an additional $5.00 per hour for each hour or part thereof in excess
of three hours. The maximum charge for any given 24-hour period is $50.00. Assume
that no car parks for longer than 24 hours at a time.
Write a program that calculates and prints the parking charges for each of three
customers who parked their cars in this garage yesterday. You should enter the
hours parked for each customer. Your program should print the results in a neat
tabular format and should calculate and print the total of yesterday’s receipts. The
program should use the function calculateCharges to determine the charge for each
customer. Your outputs should appear in the following format:

Car		Hours		Charge
1		1.5			20.0
2		4.0			25.0
3		24.0		50.0
Total	29.5		95.50
*/

#include <iostream>
#include <iomanip>
using namespace std;


//24 hours is $50 


float calculateCharges(float x) {
	float totalCharge = 0.00;

	//$20 for the first 3 hours
	if (x <= 3) {
		totalCharge = 20.00;
	}
	//ADDITIONAL $5 per hour AFTER 3 hours
	else if (x > 3 && x <= 24) {
		float additionalHours = x - 3.0;
		float additionalCharge = 5.00;
		totalCharge = 20.00 + (additionalCharge * additionalHours);

		//the maximum charge within 24 hours is $50
		if (totalCharge > 50.00) {
			totalCharge = 50.00;
		}
	}
	else {
		totalCharge = 50.00;
	}
	return totalCharge;
}

int main() {
	float carHours[3];
	float totalCharges = 0.0, totalHours = 0.0;

	//Iterating through the list of car hours.
	//The function will be called for each hour inputted
	//Calculating the charge of each hour 
	//(Alternative would be making 3 separate variables and assigning the function to them)
	for (int i = 0; i < 3; i++) {
		cout << "Enter hours parked for car " << i + 1 << ": ";
		cin >> carHours[i];
		totalCharges += calculateCharges(carHours[i]);
		totalHours += carHours[i];
	}

	cout << "Car	Hours	Charge" << endl;

	//This will print out each car hour and their respective calculated cosot
	for (int i = 0; i < 3; i++){
		cout << i+1  << "	" << fixed << setprecision(2) << carHours[i] << "	" << calculateCharges(carHours[i]) << endl;
	}
	cout << "Total	" << totalHours << "	" << fixed << setprecision(2) << totalCharges << endl; 

	return 0;
}



