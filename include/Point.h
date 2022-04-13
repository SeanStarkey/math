#ifndef POINT_H
#define POINT_H

#include <iostream>

using namespace std;

class Point
{
public:
    Point(double x, double y, double z);

private:
    double x;
    double y;
    double z;
    friend ostream& operator<<(ostream& os, const Point& pt);
};

#endif
