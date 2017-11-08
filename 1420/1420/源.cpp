#include<iostream>

#define IsEven(X) (!X&0x1)
using namespace std;

int f(__int64 A, int B, int C);
int main() {
	__int64 A, B, C;
	int Case;
	while (cin >> Case) {
		for (int step = 0; step < Case; step++) {
			cin >> A >> B >> C;
			cout << f(A, B, C)<<endl;
		}
	}
}
int f(__int64 A, int B, int C) {
	//cal A^B mod C
	
	/*Base Case*/
	if (B == 1) {
		return A%C;
	}
	else if (B == 0) {
		return 1;
	}
	if (IsEven(B)) {
		return f(A*A%C, B / 2, C);
	}
	else {
		return (A*f(A, B - 1, C))%C;
	}
}