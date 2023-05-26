#pragma once

class Complex
{
public:
	Complex(int, int);

	Complex* add(int, int);
	Complex* add(Complex*);

	int getReal() const;
	int getImaginary() const;

private:
	int real;
	int imaginary;
};