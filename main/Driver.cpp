
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

    return 0;
}
