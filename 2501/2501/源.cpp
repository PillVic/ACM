#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	double answer[30];
	answer[0] = 1;
	answer[1] = 3;
	for (int index = 2; index < 30; index++) {
		answer[index] = answer[index - 1] + 2*answer[index - 2];
	}
	int Case;
	while (cin >> Case) {
		for (int step = 0; step < Case; step++) {
			int ques;
			cin >> ques;
			cout << setprecision(0) << std::fixed << answer[ques - 1] << endl;
		}
	}
	return 0;
}