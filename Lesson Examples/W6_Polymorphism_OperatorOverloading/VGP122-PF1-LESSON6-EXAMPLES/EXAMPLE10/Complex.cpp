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

Complex* Complex::equals(Complex* c)
{
	this->real = c->real;
	this->imaginary = c->imaginary;

	return this;
}

Complex* Complex::add(Complex* c)
{
	Complex* result = new Complex();

	result->real = this->real + c->real;
	result->imaginary = this->imaginary + c->imaginary;

	return result;
}

Complex* Complex::subtract(Complex* c)
{
	Complex* result = new Complex();

	result->real = this->real - c->real;
	result->imaginary = this->imaginary - c->imaginary;

	return result;
}

Complex* Complex::multiply(Complex* c)
{
	Complex* result = new Complex();

	result->real = (this->real * c->real) - (this->imaginary * c->imaginary);
	result->imaginary = (this->real * c->imaginary) - (c->real * this->imaginary);

	return result;
}

Complex* Complex::divide(Complex* c)
{
	Complex* result = new Complex();

	result->real = (this->real * c->real + this->imaginary * c->imaginary) / (c->real * c->real + c->imaginary * c->imaginary);
	result->imaginary = (this->imaginary * c->real + this->real * c->imaginary) / (c->real * c->real + c->imaginary * c->imaginary);

	return result;
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