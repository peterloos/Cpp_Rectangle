#include <iostream>
#include <cmath>
using namespace std;

#include "Point.h"
#include "Rectangle.h"

// testing function prototypes
void test01_ctors();
void test02_methods();
void test03_center();
void test04_adjust();
void test05_move();
void test06_intersection();
void test07();

void main()
{
    test01_ctors();
    test02_methods();
    test03_center();
    test04_adjust();
    test05_move();
    test06_intersection();
    getchar();
}

void test01_ctors()
{
    Rectangle rect1;
    cout << rect1 << endl;
    Rectangle rect2(3, 3, 5, 5);
    cout << rect2 << endl;
    Rectangle rect3(3, 3, 5, 1);
    cout << rect3 << endl;
    Rectangle rect4(3, 3, 1, 1);
    cout << rect4 << endl;
    Rectangle rect5(3, 3, 1, 5);
    cout << rect5 << endl;
    Point p1(3, 3);
    Point p2(1, 2);
    Rectangle rect6(p1, p2);
    cout << rect6 << endl;
}

void test02_methods()
{
    Rectangle rect(3, 4, 9, 10);
    cout << rect << endl;
    cout << "Circumference: " << rect.Circumference() << endl;
    cout << "Diagonal:      " << rect.Diagonal() << endl;
    cout << "Area:          " << rect.Area() << endl;
    cout << "IsSquare:      " << rect.IsSquare() << endl;
}

void test03_center()
{
    Rectangle rect1(1, 3, 3, 1);
    cout << rect1 << endl;
    Point p = rect1.Center();
    cout << "Center: (" << p.GetX() << "," << p.GetY() << ')' << endl;

    Rectangle rect2(1, 4, 4, 1);
    cout << rect2 << endl;
    p = rect2.Center();
    cout << "Center: (" << p.GetX() << "," << p.GetY() << ')' << endl;
}

void test04_adjust()
{
    Rectangle rect(3, 3, 1, 1);
    cout << rect << endl;
    rect.AdjustWidth(3);
    cout << rect << endl;
    rect.AdjustWidth(-1);
    cout << rect << endl;
    rect.AdjustHeight(3);
    cout << rect << endl;
    rect.AdjustHeight(-1);
    cout << rect << endl;
}

void test05_move()
{
    Rectangle rect(1, 1, 4, 5);
    cout << rect << endl;
    rect.Move(5, -5);
    cout << rect << endl;
}

void test06_intersection()
{
    Rectangle rect1(4, 8, 9, 5);
    Rectangle rect2(2, 10, 8, 6);
    Rectangle rect = rect1.Intersection(rect2);
    cout << rect << endl;

    Rectangle rect3(7, 9, 9, 4);
    rect = rect1.Intersection(rect3);
    cout << rect << endl;

    rect = rect3.Intersection(rect3);
    cout << rect << endl;

    Rectangle rect4(6, 7, 10, 5);
    rect = rect1.Intersection(rect4);
    cout << rect << endl;
}