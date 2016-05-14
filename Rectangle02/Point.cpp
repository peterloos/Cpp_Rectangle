#include <iostream>
using namespace std;

#include "Point.h"

// c'tor(s)
Point::Point()
{
    m_x = 0;
    m_y = 0;
}

Point::Point(double x, double y)
{
    m_x = x;
    m_y = y;
}

// output
ostream& operator << (ostream& os, const Point& p)
{
    os << '(' << p.m_x << ',' << p.m_y << ')';
    return os;
}
