#include <iostream>

using namespace std;

int Sum(int n)
{
    int sum;
    if (n == 0 || n == 1)
        return n;
    else if (n > 1)
        sum = n + Sum(n - 1);
    return sum;
}

int main()
{
    int n;
    cout << "input a number" << endl;
    cin >> n;
    cout << Sum(n);
    return 0;
}