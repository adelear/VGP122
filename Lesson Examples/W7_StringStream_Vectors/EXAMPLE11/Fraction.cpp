#include "Fraction.h"

/* Fraction Constructor
	Set the numerator and denominator to the supplied parameters or 1 if no parameters are supplied */
Fraction::Fraction(int n = 1, int d = 1)
{
	numerator = n;

	if (d == 0)
		throw FractionException(DIVISION_BY_ZERO);
	else
		denominator = d;
}

/* Fraction Constructor
	Set the numerator and denominator to the supplied parameters or 1 if no parameters are supplied */
Fraction::Fraction(std::string n, std::string d)
{
	if (validate(n) && validate(d))
	{
		numerator = std::stoi(n);
		denominator = std::stoi(d);
	}
	else
		throw FractionException(LITERAL);

	if (denominator == 0)
		throw FractionException(DIVISION_BY_ZERO);
}

/* Numerator Getter
	Get the value of the numerator */
int Fraction::getNumerator()
{
	return numerator;
}

/* Numerator Setter
	Set the value of the numerator with the parameter supplied */
void Fraction::setNumerator(int n)
{
	numerator = n;
}

/* Denominator Getter
	Get the value of the denominator */
int Fraction::getDenominator()
{
	return denominator;
}

/* Denominator Setter
	Set the value of the denominator with the parameter supplied */
void Fraction::setDenominator(int d)
{
	if (d != 0)
		denominator = d;
	else
		denominator = 1;
}

/* Add Member Function
	Adds the fraction with the fraction parameter supplied */
Fraction Fraction::operator+(const Fraction& fraction)
{
	Fraction tmp;

	tmp.numerator = ((numerator * fraction.denominator) + (fraction.numerator * denominator));
	tmp.denominator = denominator * fraction.denominator;

	return tmp.simplify();
}

/* Subtract Member Function
	Sutracts the fraction with the fraction parameter supplied */
Fraction Fraction::operator-(const Fraction& fraction)
{
	Fraction tmp;

	tmp.numerator = ((numerator * fraction.denominator) - (fraction.numerator * denominator));
	tmp.denominator = denominator * fraction.denominator;

	return tmp.simplify();
}

/* Multiply Member Function
	Multiplies the fraction with the fraction parameter supplied */
Fraction Fraction::operator*(const Fraction& fraction)
{
	Fraction tmp;

	tmp.numerator = numerator * fraction.numerator;
	tmp.denominator = denominator * fraction.denominator;

	return tmp.simplify();
}

/* Divide Member Function
	Divides the fraction with the fraction parameter supplied */
Fraction Fraction::operator/(const Fraction& fraction)
{
	Fraction tmp;

	if (denominator != 0 && fraction.numerator != 0)
	{
		tmp.numerator = numerator * fraction.denominator;
		tmp.denominator = denominator * fraction.numerator;
	}

	return tmp.simplify();
}

/* operator<< Member Function
	Overloads the << operator to print fractions */
std::ostream& operator<<(std::ostream& output, const Fraction& fraction)
{
	return output << fraction.numerator << "/" << fraction.denominator;
}

/* gdc Member Function
	Finds the Greatest Common Divisor */
int Fraction::gcd(int num1, int num2)
{
	num1 = abs(num1);
	num2 = abs(num2);

	while (num1 != num2)
	{
		if (num1 > num2)
			num1 -= num2;
		else
			num2 -= num1;
	}

	return num1;
}

/* simplify Member Function
	Reduces the fraction to its lowest term */
Fraction Fraction::simplify()
{
	int commonDivisor = gcd(numerator, denominator);

	return Fraction(numerator / commonDivisor, denominator / commonDivisor);
}

/* toString Member Function
	Converts the fraction to a string representation */
std::string Fraction::toString()
{
	std::string numeratorS;
	std::string denominatorS;

	numeratorS = std::to_string(numerator);
	denominatorS = std::to_string(denominator);

	return numeratorS + "/" + denominatorS;
}

/* toDouble Member Function
	Converts the fraction to a double representation */
double Fraction::toDouble()
{
	if (denominator != 0)
	{
		return numerator / denominator;
	}

	return 0;
}

bool Fraction::validate(std::string str)
{
	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i]) == false)
			return false;

	return true;
}