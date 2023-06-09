/* Create a RationalNumber(fractions) class like the one in Exercise 9.6.
Provide the following capabilities:
a. Create the class as a template class
b. Create a constructor that prevents a 0 denominator in a fraction, reduces or simplifies
fractions that are not in reduced form and avoids negative denominators.
c. Overload the addition, subtraction, multiplication and division operators for this class.
d. Overload the relational and equality operators for this class. */

#include <iostream> 


template<typename T>

class RationalNumber   
{
private: 
	T numerator; 
	T denominator; 

	T getGCD(T num, T denom) {
		if (denom == 0) {
			return num;  
		}
		return getGCD(denom, num % denom); 
	}

	T getLCM(T num, T denom) { 
		return (num * denom) / getGCD(num, denom);
	}

public:
	RationalNumber(T numerator, T denominator) {
		if (denominator <= 0) {
			std::cout << "Error: Denominator is zero or less than zero. Please change value." << std::endl;
			return; 
		}
		this->numerator = numerator; 
		this->denominator = denominator; 

		ReduceFraction(); 
	}

	void ReduceFraction() {
		T a = numerator;
		T b = denominator;
		T gcd = 1;

		while (b != 0) {
			T temp = b;
			b = a % b;
			a = temp;
		}

		gcd = a;

		std::cout << "Reduced fraction " << numerator << "/" << denominator;

		numerator /= gcd;
		denominator /= gcd;

		std::cout << " to " << numerator << "/" << denominator << std::endl;
	} 

	RationalNumber& operator+=(const RationalNumber& other) {
		T newNumerator = (this->numerator * other.denominator) + (other.numerator * this->denominator); 
		T newDenominator = (this->denominator * other.denominator); 

		this->numerator = newNumerator; 
		this->denominator = newDenominator;

		ReduceFraction();

		return *this; 
	}
	RationalNumber& operator-=(const RationalNumber& other) {
		T newNumerator = (this->numerator * other.denominator) - (other.numerator * this->denominator); 
		T newDenominator = (this->denominator * other.denominator); 

		this->numerator = newNumerator; 
		this->denominator = newDenominator;

		ReduceFraction();

		return *this; 
	}
	RationalNumber& operator*=(const RationalNumber& other) {
		this->numerator *= other.numerator; 
		this->denominator *= other.denominator; 

		ReduceFraction(); 
		return *this; 
	}

	RationalNumber& operator/=(const RationalNumber& other) {

		if (other.numerator == 0) {
			std::cout << "Error: Cannot divide with zero in numerator." << std::endl; 
			return *this; 
		}

		this->numerator *= other.denominator;
		this->denominator *= other.numerator; 

		ReduceFraction();
		return *this;
	} 

	RationalNumber operator+(const RationalNumber& other) const { 
		RationalNumber result(*this); 
		result += other; 
		return result; 
	}
	RationalNumber operator-(const RationalNumber& other) const
	{
		RationalNumber result(*this);
		result -= other;
		return result;
	}

	RationalNumber operator*(const RationalNumber& other) const
	{
		RationalNumber result(*this);
		result *= other;
		return result;
	}

	RationalNumber operator/(const RationalNumber& other) const
	{
		RationalNumber result(*this);
		result /= other;
		return result;
	} 

	bool operator==(const RationalNumber& other) const { 
		return (this->numerator == other.numerator) && (this->denominator == other.denominator);  
	}
	bool operator!=(const RationalNumber& other) const {
		return !(*this == other); 
	}
	bool operator>(const RationalNumber& other) const {
		T commonDenominator = this->denominator * other.denominator;  
		T thisNumerator = this->numerator * other.denominator;  
		T otherNumerator = other.numerator * this->denominator;   

		return thisNumerator > otherNumerator; 
	}
	bool operator<(const RationalNumber& other) const { 
		if (*this > other) {
			return false;
		} 
		if (*this == other) {
			return false;
		} 
		return true; 
	}
	bool operator>=(const RationalNumber& other) const {
		return (*this > other) || (*this == other); 
	}

	bool operator<=(const RationalNumber& other) const {
		return (*this < other) || (*this == other); 
	}
	//The code would not run, was told to implement the code below in order to fix it 
	friend std::ostream& operator<<(std::ostream& os, const RationalNumber& rational)
	{
		os << rational.numerator << "/" << rational.denominator;
		return os;
	} 
};


int main() {
	//Initializing my two fractions 
	RationalNumber<int> num1(5, 7);
	RationalNumber<int> num2(4, 9);

	//Math operators 
	RationalNumber<int> sum = num1 + num2; 
	RationalNumber<int> difference = num1 - num2; 
	RationalNumber<int> product = num1 * num2; 
	RationalNumber<int> quotient = num1 / num2; 

	std::cout << "num1: " << num1 << std::endl; 
	std::cout << "num2: " << num2 << std::endl; 
	std::cout << "Sum: " << sum << std::endl; 
	std::cout << "Difference: " << difference << std::endl; 
	std::cout << "Product: " << product << std::endl; 
	std::cout << "Quotient: " << quotient << std::endl;  

	// Comparing the rational numbers
	bool isEqual = (num1 == num2); 
	bool isNotEqual = (num1 != num2); 
	bool isGreater = (num1 > num2); 
	bool isLess = (num1 < num2);
	bool isGreaterOrEqual = (num1 >= num2);
	bool isLessOrEqual = (num1 <= num2);

	std::cout << "isEqual: " << isEqual << std::endl;
	std::cout << "isNotEqual: " << isNotEqual << std::endl;
	std::cout << "isGreater: " << isGreater << std::endl;
	std::cout << "isLess: " << isLess << std::endl;
	std::cout << "isGreaterOrEqual: " << isGreaterOrEqual << std::endl;
	std::cout << "isLessOrEqual: " << isLessOrEqual << std::endl; 

	return 0;
}
