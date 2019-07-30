#include <iostream>

using namespace std;

struct Time{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};
int main(){
    Time T;

    cout << "plz input year" << endl;
    cin >> T.year;
    cout << "plz input month" << endl;
    cin >> T.month;
    cout << "plz input day" << endl;
    cin >> T.day;
    cout << "plz input hour" << endl;
    cin >> T.hour;
    cout << "plz input minute" << endl;
    cin >> T.minute;
    cout << "plz input second" << endl;
    cin >> T.second;

    cout << T.year;
    cout << T.month;
    cout << T.day;
    cout << T.hour;
    cout << T.minute;
    cout << T.second;

    return 0;
}