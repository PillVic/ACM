#include<iostream>
#include<math.h>

using namespace std;

bool IsFlower(int X);
int main() {
	int M;
	int N;
	while (cin >> M >> N) {
		int counter = 0;
		int arr[6];
		for (int i = M; i <= N; i++) {
			if (IsFlower(i)) {
				arr[counter] = i;
				counter += 1;
			}
		}	
		if (counter == 0) {
			cout << "no" << endl;
		}
		else {
			for (int index = 0; index < counter-1;index++) {
				cout << arr[index] << " ";
			}
			cout << arr[counter-1] << endl;
		}
	}
	return 0;
}
bool IsFlower(int X) {
	int a = X / 100;
	int b = X % 10;
	int c = (X - 100 * a - b) / 10;
	return (pow(a, 3) + pow(b, 3) + pow(c, 3)) == X;
}