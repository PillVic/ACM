/*
8*x^4 + 7*x^3 + 2*x^2 + 3*x + 6 == Y
计算该方程在(1,100)内的解，保留到小数点后四位
如果不存在，输出无解

可以显然，该函数在1,100上为单调递增函数
所以，结合函数图像，可以使用二分法来解题
*/

#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

const double t = 0.000001;

inline double f(double a,int Y){ return 8 * pow(a, 4) + 7 * pow(a, 3) + 2 * pow(a, 2) + 3 * a + 6-Y; }

void Cal(int a);

int main() {
	int Cases;
	cin >> Cases;
	for (int step = 0; step < Cases; step++) {
		int a;
		cin >> a;
		Cal(a);
	}
	return 0;
}

void Cal(int a) {
	double x = 0, y = 100;
	if (abs(f(x, a)) < t) {
		cout << fixed<<setprecision(4) << x << endl;
		return;
	}else if (abs(f(y, a)) < t) {
		cout << fixed<<setprecision(4) << y << endl;
		return;
	}else if (f(x, a)*f(y, a) > 0) {
		cout << "No solution!" << endl;
		return;
	}
	
	double n;
	while (true) {
		n = (x + y) / 2;
		if (f(x, a)*f(n, a) <= 0) {
			y = n;
		}
		else {
			x = n;
		}
		if (abs((x-y)) < t) {
			cout << fixed<<setprecision(4) << std::fixed << y << endl;
			return;
		}
	}
}