#include <iostream>

using namespace std;

int main()
{
	char mark;

	std::cout << "Enter a letter grade: ";
	std::cin >> mark;

	switch (mark)
	{
	case 'A':
	case 'a':
		std::cout << "Your grade point is 4.00";
		break;
	case 'B':
	case 'b':
		std::cout << "Your grade point is 3.00";
		break;
	case 'C':
	case 'c':
		std::cout << "Your grade point is 2.00";
		break;
	case 'D':
	case 'd':
		std::cout << "Your grade point is 1.00";
		break;
	case 'F':
	case 'f':
		std::cout << "Your grade point is 0.00";
		break;
	default:
		std::cout << "Incorrect input";
		break;
	}

	return 0;
}