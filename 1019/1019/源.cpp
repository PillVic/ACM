#include<iostream>

using namespace std;

int Gcd(int m, int n);
int Lcm(int m, int n);
int main() { 
	int Line;
	while (cin >> Line) {
		for (int line = 0; line < Line; line++) {
			int length;
			cin >> length;
			int *arr = (int*)malloc(length * sizeof(int));
			for (int index = 0; index < length; index++) {
				cin >> arr[index];
			}
			int result = arr[0];
			for (int index = 1; index < length; index++) {
				result = Lcm(result, arr[index]);
			}
			cout << result<<endl;
		}
	}
	return 0;
}
int Gcd(int m, int n) {
	int Rem;
	while (n > 0) {
		Rem = m%n;
		m = n;
		n = Rem;
	}
	return m;
}
int Lcm(int m, int n) {
	double a = m;
	double b = n;
	return a*b / Gcd(m, n);
}