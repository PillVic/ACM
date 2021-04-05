#include<iostream>
#include<math.h>

using namespace std;

int Min(int a, int b);
int Gcd(int a, int b);
int LCM(int M,int N);
int main() {
	int M, N;
	while (cin >> M>> N) {
		cout << LCM(M, N) << endl;
	}
	return 0;
}
int Min(int a, int b) {
	return a > b ? b : a;
}
int Gcd(int M, int N) {
	int Rem;
	while (N > 0) {
		Rem = M%N;
		M = N;
		N = Rem;
	}
	return M;
}
int LCM(int M, int N) {
	int CM = M*N;
	return CM / Gcd(M, N);
}

