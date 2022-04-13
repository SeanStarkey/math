#include "Point.h"


Point::Point(double in_x, double in_y, double in_z) : x(in_x), y(in_y), z(in_z)
{
}


ostream& operator<<(ostream& os, const Point& pt)
{
    os << "(" << pt.x << ", " << pt.y << ", " << pt.z << ")";
    return os;
}

