#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	fstream file;

	file.open("file.txt", ios::out);

	if (!file)
	{
		cout << "Error: File could not be created" << endl;
	}
	else
	{
		cout << "Writing to file" << endl;

		file << "Hello World!";
	}

	file.close();

	return 0;
}