#include <iostream>

struct point
{
	int x;
	int y;
};

int main()
{
	struct point p1;

	struct point* p2 = new struct point;

	p1.x = 1;
	p1.y = 1;

	std::cout << "Point p1 is at location (" << p1.x << ", " << p1.y << ")" << std::endl;

	p2->x = 2;
	p2->y = 2;

	std::cout << "Point p2 is at location (" << p2->x << ", " << p2->y << ")" << std::endl;

	delete p2;

	return 0;
}