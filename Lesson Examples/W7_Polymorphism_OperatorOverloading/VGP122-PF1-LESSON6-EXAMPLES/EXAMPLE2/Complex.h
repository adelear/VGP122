#pragma once

#include "Number.h"

class Complex : public Number
{
public:
	Complex(int, int);

	Complex* add(Complex*);
	Complex* add(int, int);

	int getReal() const;
	int getImaginary() const;
};