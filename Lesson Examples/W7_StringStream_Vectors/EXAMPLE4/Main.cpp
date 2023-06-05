#include <iostream>
#include <string>
#include <sstream>

int main()
{
	std::string word1;
	std::string word2;
	std::stringstream ss("Hello World!");

	ss >> word1;
	ss >> word2;

	std::cout << "The words are " << word1 << " and " << word2 << std::endl;

	return 0;
}