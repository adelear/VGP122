#include <iostream>

int main()
{
	int grade;

	std::cout << "Enter a grade percentage: ";
	std::cin >> grade;

	if (grade >= 90)
	{
		std::cout << "You pass with an A+";
	}
	else if (grade >= 80)
	{
		std::cout << "You pass with an A";
	}
	else if (grade >= 70)
	{
		std::cout << "You pass with a B";
	}
	else if (grade >= 60)
	{
		std::cout << "You pass with a C";
	}
	else if (grade >= 50)
	{
		std::cout << "You pass with a D";
	}
	else
	{
		std::cout << "You fail with an F";
	}

	return 0;
}