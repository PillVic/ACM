#include<iostream>
#include<stdlib.h>

using namespace std;

void Cal(int length);
int main() {
	int Line;
	int length;
	cin >> Line;
	for (int step = 0; step < Line; step++) {
		cout << "Case " << step + 1 << ":" << endl;
		int length;
		cin >> length;
		Cal(length);
		if (step != Line - 1) {
			cout << endl;
		}
	}
	return 0;
}
void Cal(int length) {
	double ThisSum;
	cin >> ThisSum;
	double MaxSum = ThisSum;
	int Thishead = 0, Thistail = 0;
	int Maxhead = 0, Maxtail = 0;
	int element;
	for (int index = 1; index < length; index++) {
		cin >> element;
		if (element >= 0&&ThisSum>=0) {
			ThisSum += element;
			Thistail = index;
		}
		else if (element < 0 && ThisSum < 0 && ThisSum < element) {
			ThisSum = element;
			Thishead = index;
			Thistail = Thishead;
		}
		else if (element >= 0&&ThisSum<0) {
			ThisSum = element;
			Thishead = index;
			Thistail = Thishead;
		}
		else {
			ThisSum += element;
			Thistail = index;
		}
		if (ThisSum > MaxSum) {
			MaxSum = ThisSum;
			Maxhead = Thishead;
			Maxtail = Thistail;
		}
	}
	cout << MaxSum << " " << Maxhead+1 << " " << Maxtail+1 << endl;
}