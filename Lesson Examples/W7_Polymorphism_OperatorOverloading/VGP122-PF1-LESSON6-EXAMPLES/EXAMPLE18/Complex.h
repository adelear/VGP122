#pragma once

#include <iostream>

using namespace std;

template<typename T>
class Complex
{
public:
	Complex();
	Complex(T, T);

	Complex& operator=(Complex const&);
	Complex& operator+(Complex const&) const;
	Complex& operator-(Complex const&) const;
	Complex& operator*(Complex const&) const;
	Complex& operator/(Complex const&) const;

	Complex& operator++();
	Complex& operator++(int);
	Complex& operator--();
	Complex& operator--(int);

	T getReal() const;
	T getImaginary() const;

	void print();

private:
	T real;
	T imaginary;
};