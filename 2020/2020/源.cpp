#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdlib.h>

using namespace std;

bool Judge(int a, int b) {
	return abs(a) > abs(b);
}

int main() {
	int Number;
	while (cin>>Number) {
		if (Number == 0) {
			continue;
		}
		int *arr = (int*)malloc(Number * sizeof(int));
		for (int index = 0; index < Number; index++) {
			cin >> arr[index];
		}
		sort(arr, arr + Number, Judge);
		for (int index = 0; index < Number; index++) {
			cout << arr[index];
			if (index + 1 != Number) {
				cout << " ";
			}
		}
		cout << endl;
	}
}
