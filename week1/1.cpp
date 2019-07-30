#include <iostream>

using namespace std;

int main()
{
	while (1) {
		cout << "is it rainy now ? Input Y or N plz" << endl;
		char n;
		cin >> n;

		if (n =='Y' ) {
			cout << "it is rainy now" << endl;
			break;
		}
		else if (n == 'N') {
			cout << "it is not rainy now" << endl;
			break;
		}
        
	}
	return 0;
}