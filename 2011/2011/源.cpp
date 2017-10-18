#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;

double Cal(int X);
int main() {
	int Number;
	while (cin >> Number) {
		int X;
		for (int index = 0; index < Number; index++) {
			cin >> X;
			cout << setprecision(2) << std::fixed <<Cal(X) << endl;
		}
	}
	return 0;
}
double Cal(int X) {
	double Sum = 0;
	for (double i = 1; i <= X; i++) {
		Sum += 1.0 / i*pow(-1,i+1);
	}
	return Sum;
}
