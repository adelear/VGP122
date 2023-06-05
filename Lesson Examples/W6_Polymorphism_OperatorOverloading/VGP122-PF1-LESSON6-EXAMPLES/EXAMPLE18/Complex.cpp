#include "Complex.h"

template<typename T>
Complex<T>::Complex()
{
	this->real = 0;
	this->imaginary = 0;
}

template<typename T>
Complex<T>::Complex(T r, T i) 
{
	this->real = r;
	this->imaginary = i;
}

template<typename T>
Complex<T>& Complex<T>::operator=(Complex<T> const& rhs)
{
	this->real = this->real + rhs.real;
	this->imaginary = this->imaginary + rhs.imaginary;

	return *this;
}

template<typename T>
Complex<T>& Complex<T>::operator+(Complex const& rhs) const
{
	Complex<T>* result = new Complex();

	result->real = real + rhs.real;
	result->imaginary = imaginary + rhs.imaginary;

	return *result;
}

template<typename T>
Complex<T>& Complex<T>::operator-(Complex<T> const& rhs) const
{
	Complex<T>* result = new Complex();

	result->real = this->real - rhs.real;
	result->imaginary = this->imaginary - rhs.imaginary;

	return *result;
}

template<typename T>
Complex<T>& Complex<T>::operator*(Complex<T> const& rhs) const
{
	Complex<T>* result = new Complex();

	result->real = (this->real * rhs.real) - (this->imaginary * rhs.imaginary);
	result->imaginary = (this->real * rhs.imaginary) - (rhs.real * this->imaginary);

	return *result;
}

template<typename T>
Complex<T>& Complex<T>::operator/(Complex<T> const& rhs) const
{
	Complex<T>* result = new Complex();

	result->real = (this->real * rhs.real + this->imaginary * rhs.imaginary) / (rhs.real * rhs.real + rhs.imaginary * rhs.imaginary);
	result->imaginary = (this->imaginary * rhs.real + this->real * rhs.imaginary) / (rhs.real * rhs.real + rhs.imaginary * rhs.imaginary);

	return *result;
}

template<typename T>
Complex<T>& Complex<T>::operator++()
{
	++real;
	++imaginary;

	return *this;
}

template<typename T>
Complex<T>& Complex<T>::operator++(int)
{
	Complex<T>* result = this;

	real++;
	imaginary++;

	return *result;
}

template<typename T>
Complex<T>& Complex<T>::operator--()
{
	--real;
	--imaginary;

	return *this;
}

template<typename T>
Complex<T>& Complex<T>::operator--(int)
{
	Complex<T>* result = this;

	real--;
	imaginary--;

	return *result;
}

template<typename T>
T Complex<T>::getReal() const
{
	return this->real;
}

template<typename T>
T Complex<T>::getImaginary() const
{
	return this->imaginary;
}

template<typename T>
void Complex<T>::print()
{
	cout << this->real << " + " << this->imaginary << "i";
}

template class Complex<int>;
template class Complex<double>;
template class Complex<float>;