#include <math.h>
#include "Vector.h"


Vector::Vector(double in_x, double in_y, double in_z) : x(in_x), y(in_y), z(in_z)
{
}


Vector Vector::operator-() const
{
    return Vector(-x, -y, -z);
}


double Vector::magnitude() const
{
    return sqrt(x*x + y*y + z*z);
}


Vector Vector::normalize() const
{
    double mag = magnitude();
    return Vector(x/mag, y/mag, z/mag);
}


ostream& operator<<(ostream& os, const Vector& v)
{
    os << "[" << v.x << ", " << v.y << ", " << v.z << "]";
    return os;
}


Vector operator*(const double s, const Vector& v)
{
    return Vector(s*v.x, s*v.y, s*v.z);
}


Vector operator*(const Vector& v, const double s)
{
    return Vector(s*v.x, s*v.y, s*v.z);
}


Vector operator+(const Vector& lhs, const Vector& rhs)
{
    return Vector(lhs.x+rhs.x, lhs.y+rhs.y, lhs.z+rhs.z);
}


Vector operator-(const Vector& lhs, const Vector& rhs)
{
    return Vector(lhs.x-rhs.x, lhs.y-rhs.y, lhs.z-rhs.z);
}
