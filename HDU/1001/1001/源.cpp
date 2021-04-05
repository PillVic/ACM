#include<iostream>
using namespace std;
int main() {
	int n = 0;
	int x = 0;
	int sum = 0;
	int times = 0;
	while (cin >> n) {

		for (x = 0; x <= n; x++) {
			sum += x;
		}
		cout << sum << endl;
		cout << endl;
		sum = 0;
	}
	return 0;
}