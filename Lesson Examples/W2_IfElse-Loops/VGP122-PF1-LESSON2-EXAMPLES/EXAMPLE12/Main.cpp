#include <iostream>

int main()
{
	int counter = 0;

	do
	{
		std::cout << "The value of the counter is " << counter << std::endl;
	} while (++counter < 10);

	return 0;
}