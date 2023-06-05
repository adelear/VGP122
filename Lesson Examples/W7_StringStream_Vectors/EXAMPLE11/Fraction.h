#pragma once

#include <iostream>
#include <string>

#include "FractionException.h"

class Fraction
{
	friend std::ostream& operator<<(std::ostream&, const Fraction&);

public:
	Fraction(int, int);
	Fraction(std::string, std::string);

	int getNumerator();
	void setNumerator(int);

	int getDenominator();
	void setDenominator(int);

	Fraction operator+(const Fraction&);
	Fraction operator-(const Fraction&);
	Fraction operator*(const Fraction&);
	Fraction operator/(const Fraction&);

	int gcd(int, int);
	Fraction simplify();

	std::string toString();
	double toDouble();

	bool validate(std::string);

private:
	int numerator;
	int denominator;
};