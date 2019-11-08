#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	double answer[20];
	answer[0] = 3;
	answer[1] = 7;
	for (int ques = 2; ques < 20; ques++) {
		//如果前一步选的是上 ，那么就有3个选择，否则(选左或者右)只有两个
		answer[ques] = answer[ques - 1] * 2 + answer[ques - 2];
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