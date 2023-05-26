// Disable CRT SECURE NO WARNINGS for c-style string errors
#pragma warning(disable: 4996);

#include <iostream>
#include <cstring>

int main()
{
	char greeting[6] = "Hello";
	char salutation[6] = "World";
	char words[12];

	std::cout << greeting << " is " << std::strlen(greeting) << " characters long" << std::endl;
	std::cout << salutation << " is " << std::strlen(salutation) << " characters long" << std::endl;

	std::strcpy(words, greeting);

	std::cout << words << std::endl;

	std::strcat(words, salutation);

	std::cout << words << std::endl;

	return 0;
}