#include <iostream>
#include <cmath>
using namespace std;

#include "Rectangle.h"

// c'tor(s)
Rectangle::Rectangle()
{
    m_x1 = 0;
    m_y1 = 0;
    m_x2 = 0;
    m_y2 = 0;
}

Rectangle::Rectangle(double x1, double y1, double x2, double y2)
{
    m_x1 = x1;
    m_y1 = y1;
    m_x2 = x2;
    m_y2 = y2;
    this->Normalize();
}

// getter/setter
void Rectangle::SetX1(double x1)
{
    m_x1 = x1;
    this->Normalize();
}

void Rectangle::SetY1(double y1)
{
    m_y1 = y1;
    this->Normalize();
}

void Rectangle::SetX2(double x2)
{
    m_x2 = x2;
    this->Normalize();
}

void Rectangle::SetY2(double y2)
{
    m_y2 = y2;
    this->Normalize();
}

// methods
double Rectangle::Circumference() const
{
    return 2 * ((m_x2 - m_x1) + (m_y1 - m_y2));
}

double Rectangle::Diagonal() const
{
    return sqrt((double)((m_x2 - m_x1) * (m_x2 - m_x1) +
        (m_y1 - m_y2) * (m_y1 - m_y2)));
}

double Rectangle::Area() const
{
    return (m_x2 - m_x1) * (m_y1 - m_y2);
}

bool Rectangle::IsSquare() const
{
    return (m_x2 - m_x1) == (m_y1 - m_y2);
}

void Rectangle::Center(double& x, double& y) const
{
    x = m_x1 + (m_x2 - m_x1) / 2.0;
    y = m_y2 + (m_y1 - m_y2) / 2.0;
}

void Rectangle::AdjustWidth(double width)
{
    m_x2 = m_x1 + width;
    this->Normalize();
}

void Rectangle::AdjustHeight(double height)
{
    m_y2 = m_y1 - height;
    this->Normalize();
}

void Rectangle::Move(double x, double y)
{
    m_x1 += x;
    m_y1 += y;
    m_x2 += x;
    m_y2 += y;
}

Rectangle Rectangle::Intersection(const Rectangle& r) const
{
    double x1, y1, x2, y2;

    if (m_x2 <= r.m_x1 || m_x1 >= r.m_x2 ||
        m_y1 <= r.m_y2 || m_y2 >= r.m_y1)
    {
        return Rectangle();
    }

    if (m_x1 < r.m_x1)
    {
        x1 = r.m_x1;
    }
    else
    {
        x1 = m_x1;
    }

    if (m_x2 < r.m_x2)
    {
        x2 = m_x2;
    }
    else
    {
        x2 = r.m_x2;
    }

    if (m_y1 > r.m_y1)
    {
        y1 = r.m_y1;
    }
    else
    {
        y1 = m_y1;
    }

    if (m_y2 > r.m_y2)
    {
        y2 = m_y2;
    }
    else
    {
        y2 = r.m_y2;
    }

    return Rectangle(x1, y1, x2, y2);
}

// output
ostream& operator << (ostream& os, const Rectangle& r)
{
    os << "Rectangle: (" << r.m_x1 << ',' << r.m_y1 << "),("
        << r.m_x2 << ',' << r.m_y2 << ") ";
    os << "[Area=" << r.Area() << ", Circumference=" << r.Circumference()
        << ", Diagonal=" << r.Diagonal() << ", IsSquare=" << r.IsSquare() << ']';

    return os;
}

// private helper methods
void Rectangle::Normalize()
{
    if (m_x1 > m_x2)
    {
        double tmp = m_x1;
        m_x1 = m_x2;
        m_x2 = tmp;
    }

    if (m_y1 < m_y2)
    {
        double tmp = m_y1;
        m_y1 = m_y2;
        m_y2 = tmp;
    }
}
