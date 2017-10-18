#include<iostream>
#include<math.h>

using namespace std;

/*
该题数据量较大
单纯递归会栈溢出
即使去除递归在未优化情况下时间复杂度，空间复杂度
两个转化妥协，均不能达到要求
该题存在隐含条件：周期性
由递推关系可得只要存在连续两个函数值与前面的函数值重复，就开始循环
f(n-1)有7种可能，f(n-2)有7种可能
2个数的可重复排列共有7*7为
*/
int foo(int A,int B,int arr[]);
int main() {
	int A, B;
	int N;
	int arr[3];
	while (cin >> A >> B >> N) {
		N = N % 49;
		if (A == 0 && B == 0 && N == 0) {
			return 0;
		}
		if (N <= 2) {
			cout << "1" << endl;
			continue;
		}
		arr[0] = 1; arr[1] = 1;
		arr[2] = (A + B) % 7;
		int head, mid;
		for(int index=4;index<=N;index++){
			head = arr[1];
			mid = arr[2];
			arr[2] = foo(A, B, arr);
			arr[0] = head;
			arr[1] = mid;
		}
		cout << arr[2]<<endl;
	}
	return 0;
}
int foo(int A, int B, int arr[]) {
	return (A*arr[2] + B*arr[1]) % 7;
}