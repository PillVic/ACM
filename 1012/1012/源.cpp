#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;
//¶¨Òå½×³Ë
double mul(int n) {
	long double k = 1.0;
	int i = 0;
	for (i = 1; i <= n; i++) {
		k = k*i;
	}
	return k;
}
int main() {
	cout << "n" << " " << "e" << endl;
	cout << "- -----------" << endl;
	const int n = 9;
	double e = 0;
	for (float i = 0; i <= n; i++) {
		e = e + 1 / mul(i);
		if (i<2) {
			printf("%.0f %.0f\n", i, e);
		}
		else if (i == 2) {
			printf("%.0f %.1f\n", i, e);
		}
		else {
			printf("%.0f %.9f\n", i, e);
		}
	}
	int view;
	cin >> view;
	return 0;
}