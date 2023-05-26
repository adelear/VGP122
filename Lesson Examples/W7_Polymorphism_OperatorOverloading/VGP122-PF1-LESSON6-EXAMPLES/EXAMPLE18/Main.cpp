#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Complex.h"

using namespace std;

int main()
{
	srand(time(0));

	Complex<int> c(rand() % 10, rand() % 10);
	Complex<int> result[10];

	int i = 0;

	fstream file;

	string line;

	file.open("file.txt", ios::in | ios::out | ios::app);

	if (!file)
	{
		cout << "Error: File could not be created" << endl;
	}
	else
	{
		cout << "Writing to file" << endl;

		file.write((char*)&c, sizeof(c));
	}

	file.close();


	file.open("file.txt", ios::in | ios::out | ios::app);

	if (!file)
	{
		cout << "Error: File could not be created" << endl;
	}


	for (i = 0; !file.eof(); ++i)
	{
		file.read((char*)&result[i], sizeof(result[i]));
	}

	for (int j = 0; j < i - 1; ++j)
	{
		cout << result[j].getReal() << " + " << result[j].getImaginary() << "i" << endl;
	}
	
	file.close();

	return 0;
}