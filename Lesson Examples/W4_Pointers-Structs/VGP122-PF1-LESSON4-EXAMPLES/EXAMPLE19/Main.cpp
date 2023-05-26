#include <iostream>

typedef union point
{
	int x;
	int y;
} Point;

int main()
{
	Point* p = new Point;

	p->x = 10;

	std::cout << "The value of the point is (" << p->x << " , " << p->y << ")" << std::endl << std::endl;

	p->y = 1;

	std::cout << "The value of the point is (" << p->x << " , " << p->y << ")" << std::endl << std::endl;

	delete p;

	return 0;
}