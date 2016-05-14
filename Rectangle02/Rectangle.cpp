#include <iostream>
#include <cmath>
using namespace std;

#include "Point.h"
#include "Rectangle.h"

// c'tor(s)
Rectangle::Rectangle() : m_p1(0, 0), m_p2(0, 0)
{
}

Rectangle::Rectangle(Point p1, Point p2) : m_p1(p1), m_p2(p2)
{
    this->Normalize();
}

Rectangle::Rectangle(double x1, double y1, double x2, double y2)
    : m_p1(x1, y1), m_p2(x2, y2)
{
    this->Normalize();
}

// getter/setter
void Rectangle::SetX1(double x)
{
    m_p1.SetX(x);
    this->Normalize();
}

void Rectangle::SetY1(double y)
{
    m_p1.SetY(y);
    this->Normalize();
}

void Rectangle::SetX2(double x)
{
    m_p2.SetX(x);
    this->Normalize();
}

void Rectangle::SetY2(double y)
{
    m_p2.SetY(y);
    this->Normalize();
}

void Rectangle::SetLeftUpper(Point p)
{
    m_p1 = p;
    this->Normalize();
}

void Rectangle::SetRightLower(Point p)
{
    m_p2 = p;
    this->Normalize();
}

// methods
double Rectangle::Circumference() const
{
    return 2 * ((m_p2.GetX() - m_p1.GetX()) + (m_p1.GetY() - m_p2.GetY()));
}

double Rectangle::Diagonal() const
{
    return sqrt((
        (m_p2.GetX() - m_p1.GetX()) * (m_p2.GetX() - m_p1.GetX()) +
        (m_p1.GetY() - m_p2.GetY()) * (m_p1.GetY() - m_p2.GetY()))
        );
}

double Rectangle::Area() const
{
    return (m_p2.GetX() - m_p1.GetX()) * (m_p1.GetY() - m_p2.GetY());
}

bool Rectangle::IsSquare() const
{
    return (m_p2.GetX() - m_p1.GetX()) == (m_p1.GetY() - m_p2.GetY());
}

Point Rectangle::Center() const
{
    return Point(
        m_p1.GetX() + (m_p2.GetX() - m_p1.GetX()) / 2.0,
        m_p2.GetY() + (m_p1.GetY() - m_p2.GetY()) / 2.0);
}

void Rectangle::AdjustWidth(double width)
{
    m_p2.SetX(m_p1.GetX() + width);
    this->Normalize();
}

void Rectangle::AdjustHeight(double height)
{
    m_p2.SetY(m_p1.GetY() - height);
    this->Normalize();
}

void Rectangle::Move(double x, double y)
{
    m_p1.SetX(m_p1.GetX() + x);
    m_p1.SetY(m_p1.GetY() + y);
    m_p2.SetX(m_p2.GetX() + x);
    m_p2.SetY(m_p2.GetY() + y);
}

Rectangle Rectangle::Intersection(const Rectangle& r) const
{
    double x1, y1, x2, y2;

    if (m_p2.GetX() <= r.m_p1.GetX() || m_p1.GetX() >= r.m_p2.GetX() ||
        m_p1.GetY() <= r.m_p2.GetY() || m_p2.GetY() >= r.m_p1.GetY())
    {
        return Rectangle();
    }

    if (m_p1.GetX() < r.m_p1.GetX())
    {
        x1 = r.m_p1.GetX();
    }
    else
    {
        x1 = m_p1.GetX();
    }

    if (m_p2.GetX() < r.m_p2.GetX())
    {
        x2 = m_p2.GetX();
    }
    else
    {
        x2 = r.m_p2.GetX();
    }

    if (m_p1.GetY() > r.m_p1.GetY())
    {
        y1 = r.m_p1.GetY();
    }
    else
    {
        y1 = m_p1.GetY();
    }

    if (m_p2.GetY() > r.m_p2.GetY())
    {
        y2 = m_p2.GetY();
    }
    else
    {
        y2 = r.m_p2.GetY();
    }

    return Rectangle(x1, y1, x2, y2);
}

// output
ostream& operator << (ostream& os, const Rectangle& r)
{
    os << "Rectangle: " << r.GetLeftUpper() << ',' << r.GetRightLower() << ' ';
    os << "[Area=" << r.Area() << ", Circumference=" << r.Circumference()
        << ", Diagonal=" << r.Diagonal() << ", IsSquare=" << r.IsSquare() << ']';

    return os;
}

// private helper methods
void Rectangle::Normalize()
{
    if (m_p1.GetX() > m_p2.GetX())
    {
        double tmp = m_p1.GetX();
        m_p1.SetX(m_p2.GetX());
        m_p2.SetX(tmp);
    }

    if (m_p1.GetY() < m_p2.GetY())
    {
        double tmp = m_p1.GetY();
        m_p1.SetY(m_p2.GetY());
        m_p2.SetY(tmp);
    }
}