#include "Number.h"

Number::Number(int r, int i)
{
	this->real = r;
	this->imaginary = i;
}

Number* Number::add(int r, int i)
{
	return new Number(this->real + r, this->imaginary + i);
}