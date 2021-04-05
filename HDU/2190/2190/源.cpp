#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	double answer[30];
	answer[0] = 1;
	answer[1] = 3;
	answer[2] = 5;
	for (int ques = 2; ques < 30; ques++) {
		answer[ques] = answer[ques - 1] + answer[ques - 2]*2;
	}
	int Number;
	int ques;
	while (cin >> Number) {
		for (int step = 0; step < Number; step++) {
			cin >> ques;
			cout << setprecision(0) << std::fixed << answer[ques - 1] << endl;
		}
	}
	return 0;
}