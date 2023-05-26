#include <iostream>

int main()
{
	int array[12] = { -45, 6, 0, 72, 1543, -89, 0, 62, -3, 1, 6453, 78 };

	for (int i = 0; i < 12; i++)
	{
		std::cout << "array[" << i << "] = " << array[i] << std::endl;
	}

	return 0;
}