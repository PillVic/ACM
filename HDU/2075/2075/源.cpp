#include<iostream>

using namespace std;

int main() {
	int Cases;
	cin >> Cases;
	while (Cases--) {
		int a, b;
		cin >> a >> b;
		if (a%b == 0) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}