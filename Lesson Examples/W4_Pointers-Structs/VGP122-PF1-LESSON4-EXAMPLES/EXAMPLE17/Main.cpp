#include <iostream>

typedef struct point
{
	int x;
	int y;
} Point;

int main()
{
	Point* p = new Point;

	p->x = 2;
	p->y = 2;

	std::cout << "Point p is at location (" << p->x << ", " << p->y << ")" << std::endl;

	delete p;

	return 0;
}