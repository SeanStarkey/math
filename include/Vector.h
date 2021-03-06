#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

using namespace std;

class Vector
{
public:
    Vector(double x, double y, double z);
    Vector operator-() const;
    double magnitude() const;
    Vector normalize() const;

private:
    double x;
    double y;
    double z;

    friend ostream& operator<<(ostream& os, const Vector& v);
    friend Vector operator*(const double s, const Vector& v);
    friend Vector operator*(const Vector& v, const double s);
    friend Vector operator+(const Vector& lhs, const Vector& rhs);
    friend Vector operator-(const Vector& lhs, const Vector& rhs);
};

#endif
