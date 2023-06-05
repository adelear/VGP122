#pragma once

#include <iostream>

using namespace std;

class Complex
{
public:
	Complex();
	Complex(double, double);

	Complex* equals(Complex*);
	Complex* add(Complex*);
	Complex* subtract(Complex*);
	Complex* multiply(Complex*);
	Complex* divide(Complex*);

	double getReal() const;
	double getImaginary() const;

	void print();

private:
	double real;
	double imaginary;
};