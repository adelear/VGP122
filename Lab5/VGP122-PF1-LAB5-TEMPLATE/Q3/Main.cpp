/* Create a SavingsAccount class. Use a static data member annualInterestRate to store the
annual interest rate for each of the savers. Each member of the class contains a private data
member savingsBalance indicating the amount the saver currently has on deposit. Provide
member function calculateMonthlyInterest that calculates the monthly interest by multiplying the
savingsBalance by annualInterestRate divided by 12; this interest should be added to
savingsBalance. Provide a static member function modifyInterestRate that sets the static
annualInterestRate to a new value. Write a driver program to test class SavingsAccount.
Instantiate two different objects of class SavingsAccount, saver1 and saver2, with balances of
$2000.00 and $3000.00, respectively. Set the annualInterestRate to 3 percent. Then calculate the
monthly interest and print the new balances for each of the savers. Then set the
annualInterestRate to 4 percent, calculate the next month’s interest and print the new balances for
each of the savers. */


#include <iostream>

class SavingsAccount {
private:
    static double annualInterestRate; //TODO: study what static does again lol 
    //A static variable possesses the property of preserving its actual value even after it is out of its scope. 
    //Thus, the static variables are able to preserve their previous value according to their previous scope, 
    //and one doesn't need to initialize them again in the case of a new scope.
    double savingsBalance;

public:
    SavingsAccount(double balance) {
        savingsBalance = balance; 
    } 
     
    static void modifyInterestRate(double newRate) {
        annualInterestRate = newRate;
    }

    void calculateMonthlyInterest() {
        double monthlyInterest = (savingsBalance * annualInterestRate) / 12;
        savingsBalance += monthlyInterest;
    }

    double getBalance() const {
        return savingsBalance;
    }
};

double SavingsAccount::annualInterestRate = 0.0;

int main() {
    SavingsAccount saver1(2000.00);
    SavingsAccount saver2(3000.00);

    SavingsAccount::modifyInterestRate(0.03);

    std::cout << "        Month 1" << std::endl;
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();
    std::cout << "Saver1 balance: $" << saver1.getBalance() << std::endl;
    std::cout << "Saver2 balance: $" << saver2.getBalance() << std::endl;

    SavingsAccount::modifyInterestRate(0.04);

    std::cout << "\n        Month 2" << std::endl;
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();
    std::cout << "Saver 1 balance: $" << saver1.getBalance() << std::endl;
    std::cout << "Saver 2 balance: $" << saver2.getBalance() << std::endl;

    return 0;
}
 