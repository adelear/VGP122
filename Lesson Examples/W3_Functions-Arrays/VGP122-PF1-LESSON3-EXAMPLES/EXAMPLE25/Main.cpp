#include <iostream>
#include <string>

int main()
{
	std::string str;

	std::cout << "Enter a string: ";
	std::getline(std::cin, str);

	std::cout << "The string you entered is " << str << std::endl;
	std::cout << "The string length is " << str.length() << std::endl;

	return 0;
}