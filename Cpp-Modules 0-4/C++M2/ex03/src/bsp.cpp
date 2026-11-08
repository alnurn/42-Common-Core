#include "Point.hpp"

long	orientation(Point const first, Point const second, Point const point)
{
	long	dx1, dy1, dx2, dy2;
	long	d;

	dx1 = second.getX().getRawBits() - first.getX().getRawBits();
	dy1 = point.getY().getRawBits() - first.getY().getRawBits();
	dy2 = second.getY().getRawBits() - first.getY().getRawBits();
	dx2 = point.getX().getRawBits() - first.getX().getRawBits();
	d = dx1 * dy1 - dy2 * dx2;
	return (d);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	long	D1;
	long	D2;
	long	D3;

	D1 = orientation(a, b, point);
	D2 = orientation(b, c, point);
	D3 = orientation(c, a, point);
	if (D1 > 0 && D2 > 0 && D3 > 0)
		return (true);
	if (D1 < 0 && D2 < 0 && D3 < 0)
		return (true);
	return (false);
}
