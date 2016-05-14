class Rectangle
{
private:
    Point m_p1;
    Point m_p2;

public:
    // c'tors
    Rectangle();
    Rectangle(Point p1, Point p2);
    Rectangle(double x1, double y1, double x2, double y2);

    // getter/setter
    double GetX1() const { return m_p1.GetX(); };
    double GetY1() const { return m_p1.GetY(); };
    double GetX2() const { return m_p2.GetX(); };
    double GetY2() const { return m_p2.GetY(); };
    Point GetLeftUpper() const { return m_p1; };
    Point GetRightLower() const { return m_p2; };
    void SetX1(double x);
    void SetY1(double y);
    void SetX2(double x);
    void SetY2(double y);
    void SetLeftUpper(Point p);
    void SetRightLower(Point p);

    // public interface
    double Circumference() const;
    double Diagonal() const;
    double Area() const;
    bool IsSquare() const;
    Point Center() const;
    void AdjustWidth(double width);
    void AdjustHeight(double height);
    void Move(double x, double y);
    Rectangle Intersection(const Rectangle& rect) const;

private:
    // private helper methods
    void Normalize();

    // output
    friend ostream& operator << (ostream& os, const Rectangle& r);
};
