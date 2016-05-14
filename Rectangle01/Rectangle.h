class Rectangle
{
private:
    double m_x1;
    double m_y1;
    double m_x2;
    double m_y2;

public:
    // c'tors
    Rectangle();
    Rectangle(double x1, double y1, double x2, double y2);

    // getter/setter
    double GetX1() { return m_x1; };
    double GetY1() { return m_y1; };
    double GetX2() { return m_x2; };
    double GetY2() { return m_y2; };
    void SetX1(double x1);
    void SetY1(double y1);
    void SetX2(double x2);
    void SetY2(double y2);

    // public interface
    double Circumference() const;
    double Diagonal() const;
    double Area() const;
    bool IsSquare() const;
    void Center(double& x, double& y) const;
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
