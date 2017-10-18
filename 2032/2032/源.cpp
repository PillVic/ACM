#include<iostream>

using namespace std;

int main() {
	int Line;
	long arr[31][31] = { 0 };
	arr[0][0] = 1;
	arr[1][0] = arr[1][1] = 1;
	for (int x = 2; x < 31; x++) {
		arr[x][0] = 1;
		arr[x][x] = 1;
		for (int y = 1; y < x; y++) {
			arr[x][y] = arr[x - 1][y - 1] + arr[x - 1][y];
		}
	}
	while (cin >> Line) {
		for (int i = 0; i < Line; i++) {
			int index=0;
			while (arr[i][index+1] != 0) {
				cout << arr[i][index] << " ";
				index++;
			}
			cout << arr[i][index];
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
