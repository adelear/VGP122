#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	fstream file;
	string line;

	file.open("file.txt", ios::in);

	if (!file)
	{
		cout << "Error: File could not be created" << endl;
	}
	else
	{
		cout << "Reading from file" << endl;

		while(getline(file, line))
		{
			cout << line;
		}
	}

	file.close();

	return 0;
}