#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Student
{
    int num;
    string name;
    char sex;
    int age;
};

int main()
{
    Student stu = {97001, "linlin", 'F', 19};
    cout << stu.age;
    cout << stu.name;
    cout << stu.sex;
    cout << stu.age;
    return 0;
}
