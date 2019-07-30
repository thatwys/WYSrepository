#include <iostream>
#include <ctime>

using namespace std;

int main() {
	srand((int)time(0));
	int a = rand() % 100;

	cout << "plz guess the number " << endl;
	int n;
	while (1) {
		cin >> n;
		if (n == a) {
			cout << "that's correct" << endl;
			break;
		}
		else if (n <= a) {
			cout << "guess bigger" << endl;
		}
		else {
			cout << "guess smaller" << endl;
		}
	}
	return 0;
}