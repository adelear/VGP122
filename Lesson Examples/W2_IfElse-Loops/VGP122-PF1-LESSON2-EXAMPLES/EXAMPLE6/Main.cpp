#include <iostream>

int main()
{
	int grade;
	char mark;

	std::cout << "Enter a grade: ";
	std::cin >> grade;

	mark = (grade >= 90 && grade <= 100) ? '+' :
		(grade >= 80 && grade < 90) ? 'A' :
		(grade >= 70 && grade < 80) ? 'B' :
		(grade >= 60 && grade < 70) ? 'C' :
		(grade >= 50 && grade < 60) ? 'D' : 'F';

	std::cout << "Your mark is " << mark << std::endl;

	return 0;
}