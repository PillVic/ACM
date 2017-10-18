#include<iostream>

using namespace std;

int main() {
	int arr[10];
	arr[0] = 1;
	arr[1] = 2;
	for (int index = 2; index < 10; index++) {
		arr[index] = (arr[index - 1] + arr[index - 2]) % 3;
	}
	int N;
	while (cin >> N) {
		if (arr[N % 8] == 0) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
	return 0;
}