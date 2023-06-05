#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	std::stringstream str;
	std::string token;
	std::string directory;
	std::string filename;
	std::string input = "images/characters/char1.png";

	str << input;

	while (std::getline(str, token, '/'))
	{
		if (token.find('.') != std::string::npos)
			filename = token;
		else
			directory += token + "/";
	}

	std::cout << filename << " is in folder " << directory << std::endl;

	return 0;
}