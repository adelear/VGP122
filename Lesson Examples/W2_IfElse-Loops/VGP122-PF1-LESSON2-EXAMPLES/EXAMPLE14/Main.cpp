#include <iostream>

int main()
{
	for (int i = 1; i <= 10; i++)
	{
		if (i == 5)
			break;

		std::cout << "The value of i is " << i << std::endl;
	}

	return 0;
}