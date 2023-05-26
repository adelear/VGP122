#include <iostream>
#include <string>

int main()
{
	std::string str1;
	std::string str2;
	std::string total;
	std::string substring;

	int pos;

	std::cout << "Enter a string: ";
	std::getline(std::cin, str1);

	std::cout << "Enter another string: ";
	std::getline(std::cin, str2);

	total = str1 + str2;

	std::cout << "The strings concatenated are " << total << std::endl;

	pos = total.find(str2, 0);

	substring = total.substr(pos, str2.length());

	std::cout << "The sub-string is " << substring << std::endl;

	return 0;
}