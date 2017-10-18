#include<iostream>
#include<math.h>

#define MIN(A,B) A<B?A:B
#define IsEven(A) !(A&0x1)

using namespace std;

int Cal(int X, int n);
int main() {
	int T;
	int N;
	while (cin >> T) {
		for (int step = 0; step < T; step++) {
			cin >> N;
			cout << Cal(N,N)%10<<endl;
		}
	}
	return 0;
}
int Cal(int X, int n) {
	X = X % 10;
	static int arr[10] = { 1,1,4,4,2,1,1,4,4,2 };
	int t = (n - 1) % arr[n % 10] + 1;
	return pow(X, t);
}

/*0 1 2 3
  1 2 3 4
  5 6 7 8
               (5-1)%4+1
0 1
1 1
2 2 4 8 6
3 3 9 7 1 
4 4 6 
5 5
6 6
7 7 9 3 1 
8 8 4 2 6
9 9 1 
*/