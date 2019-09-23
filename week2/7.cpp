#include <iostream>
#include <cmath>

using namespace std;

class Point
{
public:
    Point(int xx = 0, int yy = 0)
    {
        x = xx;
        y = yy;
    }
    Point(Point &p);
    int getx()
    {
        return x;
    }
    int gety()
    {
        return y;
    }

private:
    int x, y;
};

Point::Point(Point &p)
{
    x = p.x;
    y = p.y;
    cout << "copy constructor" << endl;
}

class Line
{
public:
    Line(Point xp1, Point xp2);
    Line(Line &l);
    double getLen()
    {
        return len;
    }

private:
    Point p1, p2;
    double len;
};

Line::Line(Point xp1, Point xp2) : p1(xp1), p2(xp2)
{
    cout << "constructor of line" << endl;
    double x = static_cast<double>(p1.getx() - p2.getx()) double y = static_cast<double>(p1.gety() - p2.gety())
        len = sqrt(x * x + y * y)
}

Line::Line(Line &l) : p1(1, p1), p2(1, p2)
{
    cout << "copy constructor of line" << endl;
    len = l.len;
}

int main()
{
    Point myp1(1, 1), myp2(4, 5);
    Line line(myp1, myp2);
    Line line2(line);
    cout << line.getLen() << endl;
    cout << line2.getLen() << endl;
    return 0;
}