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
#include <string>
 
class Rational {
private:
    int numerator;
    int denominator;
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int num, int denom) {
        numerator = num;
        denominator = denom;
    }

    void reduceFraction();
    Rational Add(const Rational& secondFraction) const;
    Rational Subtract(const Rational& secondFraction) const;
    Rational Multiply(const Rational& secondFraction) const;
    Rational Divide(const Rational& secondFraction) const;
    std::string toRationalString();
    double toDouble();
};

void Rational::reduceFraction() {
    // If numerator % denominator == 0 and other way around 
    int a = numerator;
    int b = denominator;
    int gcd = 1;

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    gcd = a; 

    numerator /= gcd;
    denominator /= gcd; 

    std::cout << numerator << "/" << denominator << std::endl;  
   
} 


Rational Rational::Add(const Rational& secondFraction) const {  
    //Create a second rational number to add onto your original fraction  
    //1/2 + 3/4 
    //Cross multiply the fractions 
    //numerator of first fraction * denominator of the second fraction 
    //denominator of first fracton * numerator of the second fraction   
    Rational newRationalNum;
    newRationalNum.numerator = (numerator * secondFraction.denominator) + (secondFraction.numerator * denominator);
    newRationalNum.denominator = (denominator * secondFraction.denominator);
    newRationalNum.reduceFraction();
    return newRationalNum;
}

Rational Rational::Subtract(const Rational& secondFraction) const {
    //Same method as add except you subtract 
    Rational newRationalNum;
    newRationalNum.numerator = (numerator * secondFraction.denominator) - (secondFraction.numerator * denominator);
    newRationalNum.denominator = (denominator * secondFraction.denominator);
    newRationalNum.reduceFraction();
    return newRationalNum;
}

Rational Rational::Multiply(const Rational& secondFraction) const {
    //numator is multipled by the other fraction's numerator, and same with denom
    Rational newRationalNum;
    newRationalNum.numerator = numerator * secondFraction.numerator;
    newRationalNum.denominator = denominator * secondFraction.denominator;
    newRationalNum.reduceFraction();
    return newRationalNum;
}

Rational Rational::Divide(const Rational& secondFraction) const {
    //take second fraction, flip denom and numerator, then same method as multiply 
    Rational newRationalNum;
    newRationalNum.numerator = numerator * secondFraction.denominator;
    newRationalNum.denominator = denominator * secondFraction.numerator;
    newRationalNum.reduceFraction();
    return newRationalNum;
}

std::string Rational::toRationalString() {
    return std::to_string(numerator) + "/" + std::to_string(denominator);
}

double Rational::toDouble() {
    return static_cast<double>(numerator) / denominator;
}

int main() {
    int num[2];
    int denom[2];

    for (int i = 0; i < 2; i++) {
        std::cout << "Enter numerator: ";
        std::cin >> num[i];
        std::cout << "Enter denominator: ";
        std::cin >> denom[i];
    }

    Rational fraction1(num[0], denom[0]);
    fraction1.reduceFraction();  
    Rational fraction2(num[1], denom[1]);
    fraction2.reduceFraction();   

    Rational sum = fraction1.Add(fraction2);
    Rational difference = fraction1.Subtract(fraction2);
    Rational product = fraction1.Multiply(fraction2);
    Rational quotient = fraction1.Divide(fraction2);

    std::cout << "Sum: " << sum.toRationalString() << std::endl;
    std::cout << "Difference: " << difference.toRationalString() << std::endl;
    std::cout << "Product: " << product.toRationalString() << std::endl;
    std::cout << "Quotient: " << quotient.toRationalString() << std::endl;
    std::cout << "As a double: " << fraction1.toDouble() << std::endl;

    return 0; 
}

