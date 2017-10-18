#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	double X;
	while (cin >> X) {
		if (X < 0) {
			X *= -1;
		}
		cout << setprecision(2) << std::fixed << X << endl;
	}
	return 0;
}