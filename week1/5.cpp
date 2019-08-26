#include <iostream>
#include <string.h>

using namespace std;

class dog
{
public:
    dog(int age1, int weight1, string name1)
    {
        this->name = name1;
        this->age = age1;
        this->weight = weight1;
    }
    int getweight()
    {
        return this->weight;
    }
    int getage()
    {
        return this->age;
    }
    string getname()
    {
        return this->name;
    }

private:
    int age;
    int weight;
    string name;
};

int main()
{
    dog d(3, 10, 'Andy');
    cout << d.getage() << endl;
    cout << d.getname() << endl;
    cout << d.getweight() << endl;
}