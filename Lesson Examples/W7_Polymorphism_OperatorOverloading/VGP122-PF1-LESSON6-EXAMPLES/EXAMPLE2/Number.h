#pragma once

class Number
{
public:
	Number(int, int);

	Number* add(int, int);

protected:
	int real;
	int imaginary;
};