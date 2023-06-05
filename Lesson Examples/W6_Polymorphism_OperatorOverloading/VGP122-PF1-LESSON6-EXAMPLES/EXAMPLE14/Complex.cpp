#include "Complex.h"

Complex::Complex()
{
	this->real = 0;
	this->imaginary = 0;
}

Complex::Complex(double r, double i) 
{
	this->real = r;
	this->imaginary = i;
}

Complex& Complex::operator+=(Complex const& rhs)
{
	this->real += rhs.real;
	this->imaginary += rhs.imaginary;

	return *this;
}

Complex& Complex::operator-=(Complex const& rhs)
{
	this->real -= rhs.real;
	this->imaginary -= rhs.imaginary;

	return *this;
}

Complex& Complex::operator*=(Complex const& rhs)
{
	this->real = (this->real * rhs.real) - (this->imaginary * rhs.imaginary);
	this->imaginary = (this->real * rhs.imaginary) - (rhs.real * this->imaginary);

	return *this;
}

Complex& Complex::operator/=(Complex const& rhs)
{
	this->real = (this->real * rhs.real + this->imaginary * rhs.imaginary) / (rhs.real * rhs.real + rhs.imaginary * rhs.imaginary);
	this->imaginary = (this->imaginary * rhs.real + this->real * rhs.imaginary) / (rhs.real * rhs.real + rhs.imaginary * rhs.imaginary);

	return *this;
}

double Complex::getReal() const
{
	return this->real;
}

double Complex::getImaginary() const
{
	return this->imaginary;
}

void Complex::print()
{
	cout << this->real << " + " << this->imaginary << "i";
}