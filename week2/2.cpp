#include <iostream>
#include <string>

using namespace std;

double power(double x,int n){
    double a = 1.0;
    while(n --){
        a *= x;
    }
    return a;
}

int main(){
    cout << "input your 8-binary number " << endl;
    int value = 0;

    for(int i = 7;i >= 0;i --){
        char c;
        cin >> c;
        if(c == '1'){
        value += static_cast<int>(power (2,a[i]));
        }
    }
    cout << value <<endl;
    return 0;
}

