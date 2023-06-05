#include <iostream>
#include <string>
#include <sstream>

int countWords(std::string);

int main()
{
	std::string input;

	std::cout << "Enter a sentence: ";
	std::getline(std::cin, input);

	std::cout << "The input contains " << countWords(input) << " words" << std::endl;

	return 0;
}

int countWords(std::string s)
{
	std::string word;
	int count = 0;
	std::stringstream sinput(s);

	while (sinput >> word)
		++count;

	return count;
}