#include <iostream>

using namespace std;

class Circle
{
public:
    Circle() {}
    Circle(int r)
    {
        this->radius = r;
    }
    double GetArea()
    {
        return this->radius * 3.14 * this->radius;
    }

private:
    int radius;
};

int main()
{
    Circle c(3);
    cout << c.GetArea() << endl;
    return 0;
}