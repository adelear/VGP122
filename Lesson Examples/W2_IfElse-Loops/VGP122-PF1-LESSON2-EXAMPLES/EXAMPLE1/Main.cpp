#include <iostream>

int main()
{
	int grade;

	std::cout << "Enter a grade percentage: ";
	std::cin >> grade;

	if (grade >= 50)
	{
		std::cout << "You pass";
	}

	return 0;
}