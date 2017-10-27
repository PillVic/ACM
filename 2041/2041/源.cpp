#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	double answer[40];
	answer[0] = 0;
	answer[1] = 1;
	answer[2] = 2;
	for (int ques = 3; ques < 40; ques++) {
		answer[ques] = answer[ques - 1] + answer[ques - 2];
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
