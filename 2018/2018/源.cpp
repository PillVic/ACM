#include<iostream>

using namespace std;

int main() {
	int n;
	int arr[55] = { 0 };
	arr[1] = 1; arr[2] = 2; arr[3] = 3;
	for (int index = 4; index < 55; index++) {
		arr[index] = arr[index - 1] + arr[index - 3];
	}
	while (cin >> n) {
		if (n == 0) {
			continue;
		}
		cout << arr[n] << endl;
	}
	return 0;
}