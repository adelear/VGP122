#include <iostream>
#include <string>

int main()
{
	std::string str;
	char* cstr;

	std::cout << "Enter a string: ";
	std::cin >> str;

	cstr = (char*)str.c_str();

	std::cout << "The string converted to an array of characters is " << cstr << std::endl;


	int i = 10;
	std::string num = std::to_string(i);
	std::string input;

	std::cout << "Integer i converted to a string is " << num << std::endl;

	std::cout << "Enter a number: ";
	std::cin >> input;

	if (!input.compare(num))
		std::cout << "Number inputted is the same as " << num << std::endl;
	else
		std::cout << "Number inputted is not the same as " << num << std::endl;

	return 0;
}