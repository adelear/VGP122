#pragma once

#include <exception>

enum FractionError
{
	DIVISION_BY_ZERO = 0,
	LITERAL = 1
};

class FractionException : public std::exception
{
public:
	FractionException(unsigned int);

	virtual const char* what() const noexcept;

private:
	unsigned int errorCode;
};