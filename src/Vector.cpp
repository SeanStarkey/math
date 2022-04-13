#include "Vector.h"


Vector::Vector(double in_x, double in_y, double in_z) : x(in_x), y(in_y), z(in_z)
{
}


ostream& operator<<(ostream& os, const Vector& v)
{
    os << "[" << v.x << "," << v.y << "," << v.z << "]";
    return os;
}
