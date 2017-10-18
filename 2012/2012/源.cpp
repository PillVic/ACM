#include<iostream>
#include<math.h>

#define F(X) (X*X+X+41)

using namespace std;

bool IsPrime(int X);
int main() {
	int X;
	int Y;
	while (cin >> X >> Y) {
		if (X == Y&&X == 0) {
			continue;
		}
		else {
			int i;
			for (i = X; i <= Y; i++) {
				if (!IsPrime(F(i))) {
					cout << "Sorry" << endl;
					break;
				}
			}if (i == Y + 1) {
				cout << "OK" << endl;
			}
		}
	}
	return 0;
}
bool IsPrime(int X) {
	int i;
	for (i = 2; i <= sqrt(X); i++) {
		if (X%i == 0) {
			return false;
		}
	}
	return true;
}