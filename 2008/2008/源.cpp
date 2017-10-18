#include<iostream>

using namespace std;

int main() {
	int Number;
	while (cin >> Number) {
		if (Number == 0) {
			continue;
		}
		int Positive=0;
		int Negative=0;
		int Zero=0;
		double element;
		for (int step = 0; step < Number; step++) {
			cin >> element;
			if (element == 0) {
				Zero += 1;
			}
			else if (element > 0) {
				Positive += 1;
			}
			else {
				Negative += 1;
			}
		}
		cout << Negative<<" " << Zero <<" "<< Positive << endl;
	}
	return 0;
}