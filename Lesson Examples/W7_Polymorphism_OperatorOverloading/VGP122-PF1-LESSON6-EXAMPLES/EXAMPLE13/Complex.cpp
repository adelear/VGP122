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

bool Complex::operator==(Complex const& rhs) const
{
	return (this->real == rhs.real) && (this->imaginary == rhs.imaginary);
}

bool Complex::operator!=(Complex const& rhs) const
{
	return (this->real != rhs.real) && (this->imaginary != rhs.imaginary);
}

bool Complex::operator>(Complex const& rhs) const
{
	return (this->real > rhs.real) && (this->imaginary > rhs.imaginary);
}

bool Complex::operator<(Complex const& rhs) const
{
	return (this->real < rhs.real) && (this->imaginary < rhs.imaginary);
}

bool Complex::operator>=(Complex const& rhs) const
{
	return (this->real <= rhs.real) && (this->imaginary <= rhs.imaginary);
}

bool Complex::operator<=(Complex const& rhs) const
{
	return (this->real <= rhs.real) && (this->imaginary <= rhs.imaginary);
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