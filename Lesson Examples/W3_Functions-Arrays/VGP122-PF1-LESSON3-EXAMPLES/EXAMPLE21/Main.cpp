#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	const int ROWS = 3;
	const int COLS = 4;

	int i, j;
	int a[ROWS][COLS];
	
	srand(time(0));

	for (i = 0; i < ROWS; ++i)
	{
		for (j = 0; j < COLS; ++j)
		{
			a[i][j] = 1 + rand() % (ROWS * COLS);
		}
	}

	for (i = 0; i < ROWS; ++i)
	{
		for (j = 0; j < COLS; ++j)
		{
			std::cout << a[i][j] << '\t';
		}

		std::cout << std::endl;
	}

	return 0;
}