/* Create a class called Rational for performing arithmetic with fractions. Write a program to test
your class. Use integer variables to represent the private data of the class— the numerator and the
denominator. Provide a constructor that enables an object of this class to be initialized when it’s
declared. The constructor should contain default values in case no initializers are provided and
should store the fraction in reduced form.

For example, the fraction 2/4 would be stored in the object as 1 in the numerator and 2 in the denominator. 

Provide public member functions that perform each of the following tasks:
a. add—Adds two Rational numbers. The result should be stored in reduced form.
b. subtract—Subtracts two Rational numbers. Store the result in reduced form.
c. multiply—Multiplies two Rational numbers. Store the result in reduced form.
d. divide—Divides two Rational numbers. The result should be stored in reduced form.
e. toRationalString—Returns a string representation of a Rational number in the form a/b, where
a is the numerator and b is the denominator.
f. toDouble—Returns the Rational number as a double. */

#include <iostream> 

class Rational {
	private:
		int numerator; 
		int denominator;  
	public:	
		Rational() {
			int numerator = 0; 
			int denom = 1; 
		}

		Rational(int num, int denom) {
			numerator = num;
			denominator = denom;  
		} 

		void setValues(int num, int denom);
		void reduceFraction();
		void printFraction();  
		Rational Add(const Rational& secondFraction) const; 
		int Subtract();
		int Multiply();
		int Divide();
		std::string toRationalString();    
		double toDouble(); 
		
		
};
void Rational::reduceFraction() {
	// If numerator % denominator == 0 and other way around 
	if (numerator % denominator == 0) {
		//Find The Greatest Common Denominator to divide both numerator and denom by
		int a = numerator;
		int b = denominator;
		int gcd; 
		while (b != 0) {
			int temp = b; 
			b = a % b; 
			a = temp; 
		}
		gcd = a; 

		numerator /= gcd; 
		denominator /= gcd;  
	}
}

void Rational::printFraction() {
	std::cout << numerator << "\\" << denominator << std::endl; 
}

Rational Rational::Add(const Rational& secondFraction) const {
	//Create a second rational number to add onto your original fraction 
	Rational newRationalNum; 
	
	//1/2 + 3/4 
	//Cross multiply the fractions 
	//numerator of first fraction * denominator of the second fraction 
	//denominator of first fracton * numerator of the second fraction  

	newRationalNum.numerator = (numerator * secondFraction.denominator) + (secondFraction.numerator * denominator); 
	newRationalNum.denominator = (denominator * secondFraction.denominator); 
	newRationalNum.reduceFraction(); 


	return newRationalNum; 
}


int main() {
	int num[2];
	int denom[2]; 

	for (int i = 0; i < 2; i++) { 
		std::cout << "Enter numerator:";
		std::cin >> num[i]; 
		std::cout << "Enter denominator:";
		std::cin >> denom[i];
	} 

	Rational fraction1(num[0], denom[0]); 
	Rational fraction2(num[1], denom[1]); 

	Rational sum = fraction1.Add(fraction2); 
	
	return 0;
}