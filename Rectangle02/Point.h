class Point
{
private:
    double m_x;
    double m_y;

public:
    // c'tor(s)
    Point();
    Point(double x, double y);

    // getter/setter
    double GetX() const { return m_x; }
    double GetY() const { return m_y; }
    void SetX(double x) { m_x = x; };
    void SetY(double y) { m_y = y; };

    // output
    friend ostream& operator << (ostream& os, const Point& p);
};