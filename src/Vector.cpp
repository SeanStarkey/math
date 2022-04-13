#include "Vector.h"


Vector::Vector(double in_x, double in_y, double in_z) : x(in_x), y(in_y), z(in_z)
{
}


Vector Vector::operator-() const
{
    return Vector(-x, -y, -z);
}


Vector operator*(const double s, const Vector& v)
{
    return Vector(s*v.x, s*v.y, s*v.z);
}


Vector operator*(const Vector& v, const double s)
{
    return Vector(s*v.x, s*v.y, s*v.z);
}


ostream& operator<<(ostream& os, const Vector& v)
{
    os << "[" << v.x << ", " << v.y << ", " << v.z << "]";
    return os;
}
