#include<iostream>

#define IsEven(X) !(X&0x1)

using namespace std;

int MyPow(int X, int n);
int main() {
	int X;
	int n;
	while (cin >> X >> n) {
		if (X == n&&X == 0) {
			break;
		}
		cout << MyPow(X, n%1000) << endl;
	}
	return 0;
}
int MyPow(int X, int n) {
	X = X % 1000;
	if (n == 1) {
		return X;
	}
	else if (n == 0) {
		return 1;
	}
	else if (IsEven(n)) {
		return MyPow(X*X, n / 2)%1000;
	}
	else {
		return X*MyPow(X, n - 1)%1000;
	}
}