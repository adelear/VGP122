#include <iostream>

void useLocal();
void useStaticLocal();
void useGlobal();

//Global Variable
int x = 1;

int main()
{
	std::cout << "Global x in main is " << x << std::endl << std::endl;

	//Outer local variable in main
	int x = 5;

	std::cout << "Local x in main outer scope is " << x << std::endl;

	{
		//Inner local variable in main
		int x = 7;

		std::cout << "Local x in main inner scope is " << x << std::endl;
	}

	std::cout << "Local x in main outer scope is still " << x << std::endl << std::endl;

	useLocal();
	useStaticLocal();
	useGlobal();

	useLocal();
	useStaticLocal();
	useGlobal();

	std::cout << "Local x in main is still " << x << std::endl;

	return 0;
}

void useLocal()
{
	//Local function variable
	int x = 25;

	std::cout << "Local x is " << x << " on entering useLocal" << std::endl;

	++x;

	std::cout << "Local x is " << x << " on exiting useLocal" << std::endl << std::endl;
}

void useStaticLocal()
{
	//Local static functon variable
	static int x = 50;

	std::cout << "Local static x is " << x << " on entering useStaticLocal" << std::endl;

	++x;

	std::cout << "Local static x is " << x << " on exiting useStaticLocal" << std::endl << std::endl;
}

void useGlobal()
{
	std::cout << "Local x is " << x << " on entering useGlobal" << std::endl;

	++x;

	std::cout << "Local x is " << x << " on exiting useGlobal" << std::endl << std::endl;
}