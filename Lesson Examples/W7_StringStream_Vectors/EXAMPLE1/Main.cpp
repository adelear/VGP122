#include <iostream>
#include <string>
#include <sstream>

int main()
{
	int num;
	std::string s = "Hello World!";
	std::stringstream ss(s);

	std::cout << "The string is " << ss.str() << std::endl;

	return 0;
}