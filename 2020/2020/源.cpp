#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int m, n;
	while (cin >> n >> m) {
		if (n == m&&n == 0) {
			continue;
		}
		int *arr = (int*)malloc((n+1) * sizeof(int));
		for (int index = 0; index < n; index++) {
			cin >> arr[index];
		}
		arr[n] = m;
		sort(arr, arr+(n+1));
		for (int index = 0; index < n; index++) {
			cout << arr[index] << " ";
		}
		cout << arr[n]<<endl;
	}
	return 0;
}