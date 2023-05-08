#include "Point.hpp"

/*bool bsp( Point const a, Point const b, Point const c, Point const point) {
    Fixed as_x = point.getX() - a.getX();
    Fixed as_y = point.getY() - a.getY();

    bool s_ab = (b.getX() - a.getX()) * as_y - (b.getY() - a.getY()) * as_x > 0;

    if (((c.getX() - a.getX()) * as_y - (c.getY() - a.getY()) * as_x > 0) == s_ab)
        return (false);
    if (((c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY()) * (point.getX() - b.getX()) > 0) != s_ab) 
        return false;
    return (true);
}*/

/*bool bsp( Point const a, Point const b, Point const c, Point const point) {
    Fixed s = (a.getX() - c.getX()) * (point.getY() - c.getY()) - (a.getY() - c.getY()) * (point.getX() - c.getX());
    Fixed t = (b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX());

    if ((s < 0) != (t < 0) && s != 0 && t != 0)
        return false;

    Fixed d = (c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY()) * (point.getX() - b.getX());
    std::cout << d << std::endl;
    return d == 0 || (d < 0) == (s + t <= 0);
}*/

static Fixed triangleArea(const Point &a, const Point &b, const Point &c)
{
	Fixed area = Fixed(a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()));
	if (area < 0)
		area = area * -1;
	return (area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed abc = triangleArea(a, b, c);
	Fixed abp = triangleArea(a, b, point);
	Fixed acp = triangleArea(a, c, point);
	Fixed bcp = triangleArea(b, c, point);

    if (abp == 0 || acp == 0 || bcp == 0) {
        return (false);
    }
	if (abc == abp + acp + bcp)
		return (true);
	return (false);
}