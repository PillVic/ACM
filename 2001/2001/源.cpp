#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;

int main() {
	double X1, Y1;
	double X2, Y2;
	while (cin >> X1>>Y1>>X2>>Y2) {
		double distanceX = pow(X1 - X2, 2);
		double distanceY = pow(Y1 - Y2, 2);
		double Distance = sqrt(distanceX + distanceY);
		cout << setprecision(2) << std::fixed << Distance << endl;
	}
	return 0;
}