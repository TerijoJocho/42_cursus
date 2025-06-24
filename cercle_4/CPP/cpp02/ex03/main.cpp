
#include "PointClass/Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	Point	a(0.0f, 0.0f);
	Point	b(4.0f, 0.0f);
	Point	c(2.0f, 4.0f);
	Point	point(2.0f, 2.0f);

	std::cout << "a.x: " << a.getX() << ", a.y: " << a.getY() << std::endl;
	std::cout << "b.x: " << b.getX() << ", b.y: " << b.getY() << std::endl;
	std::cout << "c.x: " << c.getX() << ", c.y: " << c.getY() << std::endl;
	std::cout << "point.x: " << point.getX() << ", point.y: " << point.getY() << std::endl;
	if (bsp(a, b, c, point))
	{
		std::cout << "Point belongs to abc triangle" << std::endl;
	}
	else
		std::cout << "Point does not belongs to abc triangle" << std::endl;

	return 0;
}
