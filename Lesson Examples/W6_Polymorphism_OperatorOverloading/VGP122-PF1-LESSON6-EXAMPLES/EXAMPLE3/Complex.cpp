#include "Complex.h"

Complex::Complex(int r, int i) : Number(r, i)
{

}

/*Complex* Complex::add(int r, int i)
{
	return (Complex*)Number::add(r, i);
}*/

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