#include <iostream>

int main()
{
	char grade;
	int gradeCounter = 0;
	float average = 0.0f;

	std::cout << "Enter a letter grade (or CTRL+Z to quit): ";

	while ((grade = std::cin.get()) != EOF)
	{
		std::cin.ignore(256, '\n');

		switch (grade)
		{
		case 'A':
		case 'a':
			average += 4.0f;
			gradeCounter++;
			break;
		case 'B':
		case 'b':
			average += 3.0f;
			gradeCounter++;
			break;
		case 'C':
		case 'c':
			average += 2.0f;
			gradeCounter++;
			break;
		case 'D':
		case 'd':
			average += 1.0f;
			gradeCounter++;
			break;
		case 'F':
		case 'f':
			gradeCounter++;
			break;
		default:
			std::cout << "Invalid input" << std::endl;
			break;
		}

		std::cout << "Enter a letter grade (or CTRL+Z to quit): ";
	}

	if (gradeCounter == 0)
		std::cout << "The average GPA is " << average << std::endl;
	else
		std::cout << "The average GPA is " << (average / gradeCounter) << std::endl;

	return 0;
}