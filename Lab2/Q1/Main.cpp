/* Develop a C++ program that will determine whether a department-store customer has
exceeded the credit limit on a charge account. For each customer, the following facts are
available:
a. Account number (an integer)
b. Balance at the beginning of the month
c. Total of all items charged by this customer this month
d. Total of all credits applied to this customer's account this month
e. Allowed credit limit

The program should use a while statement to input each of these facts, calculate the new
balance (= beginning balance + charges – credits) and determine whether the new balance
exceeds the customer’s credit limit. For those customers whose credit limit is exceeded, the
program should display the customer’s account number, credit limit, new balance and the
message "Credit Limit Exceeded."

Enter account number (or -1 to quit): 100
Enter beginning balance: 5394.78
Enter total charges: 1000.00
Enter total credits: 500.00
Enter credit limit: 5500.00
New balance is 5894.78
Account: 100
Credit limit: 5500.00
Balance: 5894.78
Credit Limit Exceeded.
Enter Account Number (or -1 to quit): 200
Enter beginning balance: 1000.00
Enter total charges: 123.45
Enter total credits: 321.00
Enter credit limit: 1500.00
New balance is 802.45
Enter Account Number (or -1 to quit): -1 */

#include <iostream>
using namespace std;

int main() {

	int accountNum = 0;
	double initialBalance, totalCharges, creditsApplied, creditLimit;
	bool isRunning = true; 

	do {
		cout << "Enter account number (or -1 to quit): ";
		cin >> accountNum;

		if (accountNum != -1) {
			cout << "Enter beginning balance: ";
			cin >> initialBalance;

			cout << "Enter total charges: ";
			cin >> totalCharges;

			cout << "Enter total credits: ";
			cin >> creditsApplied;

			cout << "Enter credit limit: ";
			cin >> creditLimit;

			initialBalance = initialBalance + totalCharges - creditsApplied;
			cout << "New Balance is " << initialBalance << endl;

			if (initialBalance > creditLimit) {
				cout << "Account: " << accountNum << endl;
				cout << "Credit Limit: " << creditLimit << endl;
				cout << "Balance: " << initialBalance << endl;
				cout << "Credit Limit Exceeded." << endl;
			}
		}
	} while (accountNum != -1);

	return 0;
}

