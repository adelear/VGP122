#include <iostream>
#include <string>
#include <sstream>

int main()
{
	std::string word1 = "Hello";
	std::string word2 = "World";
	std::stringstream ss;

	ss << word1 << " " << word2;

	std::cout << "The words concatenated are " << ss.str() << std::endl;

	return 0;
}