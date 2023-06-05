#pragma once

#include <iostream>

using namespace std;

class Complex
{
public:
	Complex();
	Complex(double, double);

	bool operator==(Complex const&) const;
	bool operator!=(Complex const&) const;
	bool operator>(Complex const&) const;
	bool operator<(Complex const&) const;
	bool operator>=(Complex const&) const;
	bool operator<=(Complex const&) const;

	double getReal() const;
	double getImaginary() const;

	void print();

private:
	double real;
	double imaginary;
};