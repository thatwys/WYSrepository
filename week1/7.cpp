#include <iostream>

using namespace std;

class Rectangle
{
public:
    Rectangle() {}
    Rectangle(int w, int h)
    {
        this->width = w;
        this->height = h;
    }
    int Area()
    {
        return this->height * this->width;
    }

private:
    int width;
    int height;
};

int main()
{
    Rectangle A(1, 3);
    cout << "the area is" << A.Area() << endl;
    return 0;
}