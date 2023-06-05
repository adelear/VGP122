#include <iostream>
#include <string>
#include <sstream>

int main()
{
	int num;
	std::string s;
	std::stringstream str;

	std::cout << "Enter a number: ";
	std::cin >> num;

	str << num;
	str >> s;

	std::cout << "And the number as a string is " << s << std::endl;

	return 0;
}