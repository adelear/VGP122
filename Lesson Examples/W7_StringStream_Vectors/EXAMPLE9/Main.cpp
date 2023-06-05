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

	std::vector<int>::iterator it = v1.begin();

	while (it != v1.end())
	{
		std::cout << *it << std::endl;

		++it;
	}

	for (int i = 0; i < num; ++i)
	{
		std::cout << "Removing item " << v1.back() << " from vector" << std::endl;

		v1.pop_back();
	}

	return 0;
}