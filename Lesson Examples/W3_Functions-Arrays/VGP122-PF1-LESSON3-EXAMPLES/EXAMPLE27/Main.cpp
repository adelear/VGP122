#include <iostream>
#include <string>

int main()
{
	std::string str1;
	std::string str2;

	std::cout << "Enter a string: ";
	std::getline(std::cin, str1);

	std::cout << "Enter another string: ";
	std::getline(std::cin, str2);

	if (str1 == str2)
		std::cout << "The strings you entered are the same";
	else
		std::cout << "The strings you entered are not the same";

	std::cout << std::endl;

	if (str1 < str2)
		std::cout << "The first string is smaller";
	else if (str1 > str2)
		std::cout << "The second string is smaller";

	return 0;
}