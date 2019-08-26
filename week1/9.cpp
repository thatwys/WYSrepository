#include <iostream>

using namespace std;

class Tree
{
public:
    Tree() {}
    Tree(int t)
    {
        this->ages = t;
    }
    int grow(int a)
    {
        this->ages += a;
        return this->ages;
    }
    int age()
    {
        return this->ages;
    }

private:
    int ages;
};

int main()
{
    Tree t = 1;
    t.grow(6);
    cout << t.age() << endl;
    return 0;
}