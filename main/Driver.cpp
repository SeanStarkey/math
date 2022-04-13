
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

    return 0;
}
