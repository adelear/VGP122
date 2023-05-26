#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));

	for (int counter = 1; counter <= 20; ++counter)
	{
		std::cout << (1 + rand() % 6) << " ";
	}

	return 0;
}