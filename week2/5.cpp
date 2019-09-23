#include <iostream>

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

void fun1(Point &p)
{
    cout << p.getx() << endl;
}

Point fun2()
{
    Point a(1, 2);
    return a;
}

int main()
{
    Point a(4, 5);
    Point b = a;
    cout << b.getx() << endl;
    fun1(b);
    b = fun2();
    cout << b.getx() << endl;
    return 0;
}