
#include <iostream>

using namespace std;

class Rectangle
{
public:
    Rectangle(){};
    Rectangle(int iLeftX, int iLeftY, int iRightX, int iRightY)
    {
        this->iLeftX = iLeftX;
        this->iLeftY = iLeftY;
        this->iRightX = iRightX;
        this->iRightY = iRightY;
    }
    int Area()
    {
        return (iRightX - iLeftX) * (iRightY - iLeftY);
    }

private:
    int iLeftX;
    int iLeftY;
    int iRightX;
    int iRightY;
};

int main()
{
    Rectangle r(1, 1, 2, 2);
    cout << "这个矩形的面积是：" << r.Area() << endl;
    return 0;
}
