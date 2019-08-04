#include <iostream>

using namespace std;

double power(double x,int n){
    double a = 1.0;
    while(n --){
        a *= x;
    }
    return a;
}
int main(){
    cout << "input two numbers" <<endl;
    double n;
    int m;
    cin >> n >> m;
    cout << "the answer is " << power(n,m) <<endl;
    return 0;
}