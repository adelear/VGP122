#include <iostream>

int main()
{
	// Declare and initialize an array of characters
	char greeting[6] = { 'H', 'e', 'l', 'l', 'o', '\0' };

	std::cout << greeting << std::endl;

	// Print the value for each character stored in the array
	for(int i = 0; i < 6; ++i)
		std::cout << greeting[i] << std::endl;

	return 0;
}