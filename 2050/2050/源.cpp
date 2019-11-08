#include<iostream>
#include<iomanip>

using namespace std;

double Cal(int index);
int main() {
	int Case;
	int index;
	while (cin >> Case) {
		for (int step = 0; step < Case; step++) {
			cin >> index;
			cout << setprecision(0) << std::fixed << Cal(index) << endl;
		}
	}
	return 0;
}
double Cal(int index) {
	if (index == 1) {
		return 2;
	}
	else {
		return Cal(index - 1) + 4 * (index - 1) + 1;
	}
}