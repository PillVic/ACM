#include<iostream>
#include<algorithm>
#include<stdlib.h>

using namespace std;
int main() {
	int T;
	while (cin >> T) {
		for (int step = 0; step < T; step++) {
			int N;
			cin >> N;
			int *arr = (int*)malloc(N * sizeof(int));
			for (int index = 0; index < N; index++) {
				cin >> arr[index];
			}
			sort(arr, arr + N);
			for (int index = 0; index < N-1; index++) {
				cout << arr[index] << " ";
			}
			cout << arr[N - 1];
			cout << endl;
			free(arr);
		}
	}
}