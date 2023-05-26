#include <iostream>

using namespace std;

int main()
{
	char grade;
	int i = 0, maxGrades;
	float average = 0.0f;

	std::cout << "How many grades will you be entering: ";
	std::cin >> maxGrades;

	while (i < maxGrades)
	{
		std::cout << "Enter a letter grade: ";
		std::cin >> grade;

		switch (grade)
		{
		case 'A':
		case 'a':
			average += 4.0f;
			i++;
			break;
		case 'B':
		case 'b':
			average += 3.0f;
			i++;
			break;
		case 'C':
		case 'c':
			average += 2.0f;
			i++;
			break;
		case 'D':
		case 'd':
			average += 1.0f;
			i++;
			break;
		case 'F':
		case 'f':
			i++;
			break;
		default:
			std::cout << "Invalid input" << std::endl;
			break;
		}
	}

	if (maxGrades == 0)
		std::cout << "The average GPA is " << average << std::endl;
	else
		std::cout << "The average GPA is " << (average / maxGrades) << std::endl;

	return 0;
}