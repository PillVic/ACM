#include<iostream>
using namespace std;
int MaxSubSum(const int arr[], int N, int *bgn, int *end);
int main() {
	int Line;
	cin >> Line;
	for (int i = 0; i < Line; i++) {
		int bgn = 1, end = 1;
		int T;
		cin >> T;
		int *arr = new int[T];
		for (int j = 0; j < T; j++) {
			cin >> arr[j];
		}
		int MaxSum = MaxSubSum(arr, T, &bgn, &end);
		cout << "Case " << i + 1 << ":" << endl;
		cout << MaxSum << " " << bgn << " " << end << endl;
		if (i != Line - 1) {
			cout << endl;
		}
	}
	return 0;
}
int MaxSubSum(const int arr[], int N, int *bgn,int *end) {
	int MaxSum = -1001;
	int ThisSum = 0;
	int nbgn = 1;
	int nend = 1;
	for (int j = 0; j < N; j++) {
		ThisSum += arr[j];
		nend = j + 1;
		if (ThisSum > MaxSum) {
			MaxSum = ThisSum;
			*bgn = nbgn;
			*end = nend;
		}
		else if (ThisSum < 0) {
			ThisSum = 0;
			nend = nbgn = j + 1;
		}
	}
	return MaxSum;
}


#include <iostream>

using namespace std;

int main(){
	int T, N, num, startP, endP;
	cin >> T;
	for (int k = 0; k<T; k++){
		cin >> N;
		int max = -1001, sum = 0, temp = 1;
		for (int i = 0; i<N; i++){
			cin >> num;
			sum += num;
			if (sum>max){
				max = sum;
				startP = temp;
				endP = i + 1;
			}
			if (sum<0){
				sum = 0;
				temp = i + 2;
			}
		}
		cout << "Case " << k + 1 << ":" << endl;
		cout << max << " " << startP << " " << endP << endl;
		if (k != T - 1) cout << endl;
	}
}