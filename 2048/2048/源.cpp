#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	int T;
	while (cin >> T) {
		for (int step = 0; step < T; step++) {
			int N;
			cin >> N;
			double t = 1.0;
			for (double i = 1; i <= N; i++) {
				t *= 1 / i;
			}
			t *= 100;
			cout << setprecision(2) << std::fixed << t << "%" << endl;
		}
	}
	return 0;
}