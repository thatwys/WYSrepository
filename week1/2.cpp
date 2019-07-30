#include <iostream>

using namespace std;

int main()
{
	cout << "how much grades do u get" << endl;
	int n;
	cin >> n;
	switch (n / 100) {
	case 9 && 10: 
	    cout << "great" << endl;
	    break;
	case 8 :
		cout << "good" << endl;
		break;
	case 7 :
		cout << "ok" << endl;
		break;
	default :
		cout << "not good" << endl;
		break;
	}
	return 0;
}