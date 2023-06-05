#include "Complex.h"

Complex::Complex(int r, int i)
{
	this->real = r;
	this->imaginary = i;
}

Complex* Complex::add(int r, int i)
{
	return new Complex(this->real + r, this->imaginary + i);
}

Complex* Complex::add(Complex* c)
{
	return new Complex(this->real + c->real, this->imaginary + c->imaginary);
}

int Complex::getReal() const
{
	return this->real;
}

int Complex::getImaginary() const
{
	return this->imaginary;
}