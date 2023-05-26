#pragma once

#include "Number.h"

class Complex : public Number
{
public:
	Complex(int, int);

	Complex* add(Complex*);

	int getReal() const;
	int getImaginary() const;
};