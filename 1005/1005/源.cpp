#include<iostream>
#include<math.h>

using namespace std;

/*
�����������ϴ�
�����ݹ��ջ���
��ʹȥ���ݹ���δ�Ż������ʱ�临�Ӷȣ��ռ临�Ӷ�
����ת����Э�������ܴﵽҪ��
�����������������������
�ɵ��ƹ�ϵ�ɵ�ֻҪ����������������ֵ��ǰ��ĺ���ֵ�ظ����Ϳ�ʼѭ��
f(n-1)��7�ֿ��ܣ�f(n-2)��7�ֿ���
2�����Ŀ��ظ����й���7*7Ϊ
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