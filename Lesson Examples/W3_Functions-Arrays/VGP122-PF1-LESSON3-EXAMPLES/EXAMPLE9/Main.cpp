#include <iostream>

void function1();
void function2(void);

int main()
{
	function1();
	function2();

	return 0;
}

void function1()
{
	std::cout << "function1 takes no parameters" << std::endl;
}

void function2(void)
{
	std::cout << "function2 takes no parameters" << std::endl;
}