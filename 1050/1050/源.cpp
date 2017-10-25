#include<iostream>
#include<math.h>

#define IsEven(X) !(X&1)
#define N 200
using namespace std;

int gate(int index);
void Initial(int arr[], int length);
void Move(int arr[], int start, int end);
int main() {
	int Rooms[N];
	int Case;
	int Number;
	while (cin >> Case) {
		for (int step = 0; step < Case; step++) {
			Initial(Rooms, N);
			int start, end;
			cin >> Number;
			for (int index = 0; index < Number; index++) {
				cin >> start >> end;
 				if (start > end) {
					Move(Rooms, end, start);
					continue;
				}
				Move(Rooms, start, end);
			}
			int max = Rooms[0];
			for (int index = 0; index < N; index++) {
				if (max < Rooms[index]) {
					max = Rooms[index];
				}
			}
			cout << max * 10 << endl;
		}
	}

	return 0;
}
int gate(int index) {
	return int(ceil((index-1) / 2));
}
void Initial(int arr[], int length) {
	for (int index = 0; index < length; index++) {
		arr[index] = 0;
	}
}
void Move(int arr[], int start, int end) {
	int num=-1;
	for (int index = start; index <= end; index++) {
		if (num == gate(index)) {
			continue;
		}
		num = gate(index);
		arr[num] += 1;
	}
}