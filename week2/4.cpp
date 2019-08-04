#include <iostream>

using namespace std;

bool PrimeOrNot(int n){
	for (int i = 2; i < n; i ++) {
		if (n % i == 0) {
			cout << n << " isn't a prime" << endl;
			return 1;
		}
	}
	cout << n << " is a prime" << endl;
	return 0;
}
int main() {
	int n;
	cin >> n;
	PrimeOrNot(n);
	return 0;
}