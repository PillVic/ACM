#include<iostream>

using namespace std;

int main() {
	double arr[3];
	int M;
	while (cin >> M) {
		for (int step = 0; step < M; step++) {
			cin >> arr[0] >> arr[1] >> arr[2];

			if (arr[2]<(arr[1]+arr[0])
				&&arr[1]<(arr[0]+arr[2])
				&&arr[0]<(arr[1]+arr[2])
				&&arr[0]>0&&arr[1]>0&&arr[2]>0
				) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}