#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

int main() {
	double N;
	double M;
	while (cin >> M >> N) {
		double Sum = 0;
		for (int step = 0; step < N; step++) {
			Sum += M;
			M = sqrt(M);
		}
		cout << setprecision(2)<<std::fixed<<Sum << endl;
	}
	return 0;
}