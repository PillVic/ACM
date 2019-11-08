#include<iostream>

#define IsEven(A) !(A&0x1)

using namespace std;

int main() {
	int Number;
	while (cin >> Number) {
		int Pro = 1;
		int ele;
		for (int index = 0; index < Number; index++) {
			cin >> ele;
			if (!IsEven(ele)) {
				Pro *= ele;
			}
		}
		cout << Pro << endl;
	}
	return 0;
}