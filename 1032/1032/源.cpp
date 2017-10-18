#include<iostream>

using namespace std;

#define MAX(A,B) A>B?A:B

int PrintN(int N,int length);

int main() {
	int i,j;
	int maxlength=0;
	int a = 0;
	int b = 0;
	while (cin >> i>>j) {
		b = MAX(i, j);
		a = i + j - b;
		for (int num = a; num <= b; num++) {
			int length = PrintN(num, 0);
			if (maxlength < length) {
				maxlength = length;
			}
		}
		cout << i << " " << j << " " << maxlength << endl;
		maxlength = 0;
	}
	return 0;
}
//将尾递归优化为函数内部循环，解决N过大时的栈溢出问题
int PrintN(int N, int length) {
begining:
	if (N == 1) {
		return length + 1;
	}
	else if (N % 2 == 0) {
		N = N / 2;
		length += 1;
		goto begining;
	}
	else {
		N = 3 * N + 1;
		length += 1;
		goto begining;
	}
}