#include "FractionException.h"

FractionException::FractionException(unsigned int num) : errorCode(num)
{ }

const char* FractionException::what() const noexcept
{
	switch (errorCode)
	{
	case DIVISION_BY_ZERO:
		return "Error: Division by zero";
		break;
	case LITERAL:
		return "Error: Enter a number";
		break;
	default:
		return "Error: Error Unknown";
	}
}