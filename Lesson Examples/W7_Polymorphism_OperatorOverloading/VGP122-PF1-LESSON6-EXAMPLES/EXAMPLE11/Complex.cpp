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

Complex& Complex::operator=(Complex const& rhs)
{
	this->real = this->real + rhs.real;
	this->imaginary = this->imaginary + rhs.imaginary;

	return *this;
}

Complex& Complex::operator+(Complex const& rhs) const
{
	Complex* result = new Complex();

	result->real = real + rhs.real;
	result->imaginary = imaginary + rhs.imaginary;

	return *result;
}

Complex& Complex::operator-(Complex const& rhs) const
{
	Complex* result = new Complex();

	result->real = this->real - rhs.real;
	result->imaginary = this->imaginary - rhs.imaginary;

	return *result;
}

Complex& Complex::operator*(Complex const& rhs) const
{
	Complex* result = new Complex();

	result->real = (this->real * rhs.real) - (this->imaginary * rhs.imaginary);
	result->imaginary = (this->real * rhs.imaginary) - (rhs.real * this->imaginary);

	return *result;
}

Complex& Complex::operator/(Complex const& rhs) const
{
	Complex* result = new Complex();

	result->real = (this->real * rhs.real + this->imaginary * rhs.imaginary) / (rhs.real * rhs.real + rhs.imaginary * rhs.imaginary);
	result->imaginary = (this->imaginary * rhs.real + this->real * rhs.imaginary) / (rhs.real * rhs.real + rhs.imaginary * rhs.imaginary);

	return *result;
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