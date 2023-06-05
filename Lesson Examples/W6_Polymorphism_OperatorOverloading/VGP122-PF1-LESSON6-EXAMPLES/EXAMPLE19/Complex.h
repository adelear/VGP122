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

	Complex& operator+=(Complex const&);
	Complex& operator-=(Complex const&);
	Complex& operator*=(Complex const&);
	Complex& operator/=(Complex const&);

	bool operator==(Complex const&) const;
	bool operator!=(Complex const&) const;
	bool operator>(Complex const&) const;
	bool operator<(Complex const&) const;
	bool operator>=(Complex const&) const;
	bool operator<=(Complex const&) const;

	T getReal() const;
	T getImaginary() const;

	friend ostream& operator<< <T>(ostream&, const Complex&);

private:
	T real;
	T imaginary;
};

template<typename T>
ostream& operator<<(ostream& out, const Complex<T>& c)
{
	out << c.getReal() << " + " << c.getImaginary() << "i";

	return out;
}