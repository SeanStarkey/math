#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

using namespace std;

class Vector
{
public:
    Vector(double x, double y, double z);

private:
    double x;
    double y;
    double z;
    friend ostream& operator<<(ostream& os, const Vector& v);
};

#endif
