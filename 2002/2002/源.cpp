#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;

int main() {
	double Radius;
	const double PI = 3.1415927;
	while (cin >> Radius) {
		cout << setprecision(3) << std::fixed << PI*pow(Radius, 3)*4.0/3 << endl;
	}
	return 0;
}