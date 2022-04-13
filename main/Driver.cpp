
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Point.h"
#include "Vector.h"

using namespace std;

int main()
{
    Point p1(1, 2, 3);
    cout << p1 << endl;

    Vector v1(1, 2, 3);
    cout << v1 << endl;

    Vector v2 = -v1;
    cout << v2 << endl;

    Vector v3 = 3 * v1;
    cout << v3 << endl;

    Vector v4 = v1 * 5;
    cout << v4 << endl;

    Vector v5(2, -3, 5);
    Vector v6(7, 11, -13);

    cout << v5+v6 << endl;
    cout << v5-v6 << endl;

    Vector v7(1, 4, 8);
    cout << v7.magnitude() << endl;

    cout << v7.normalize() << endl;

    return 0;
}
