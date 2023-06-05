#include <iostream>
#include <vector>

int main()
{
	int num;
	int input;
	std::vector<int> v1;

	std::cout << "How many numbers will you be entering: ";
	std::cin >> num;

	v1.reserve(num);

	for (int i = 0; i < num; ++i)
	{
		std::cout << "Enter a number: ";
		std::cin >> input;

		v1.push_back(input);
	}

	for(auto item : v1)
		std::cout << item << std::endl;

	return 0;
}