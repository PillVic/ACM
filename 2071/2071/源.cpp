#include<iostream>
#include<iomanip>
#include<algorithm>

using namespace std;

int main() {
	int Cases;
	cin >> Cases;
	while (Cases--) {
		int length;
		cin >> length;
		double *num = new double[length];
		for (int i = 0; i < length; i++) {
			cin >> num[i];
		}
		sort(num, num + length);
		cout << std::fixed << setprecision(2) << num[length-1] << endl;
		free(num);
	}
	return 0;
}