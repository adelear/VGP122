#pragma once

#include <iostream>

using namespace std;

class Complex
{
public:
	Complex();
	Complex(double, double);

	Complex& operator=(Complex const&);
	Complex& operator++();
	Complex& operator++(int);
	Complex& operator--();
	Complex& operator--(int);

	double getReal() const;
	double getImaginary() const;

	void print();

private:
	double real;
	double imaginary;
};