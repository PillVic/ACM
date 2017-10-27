#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	double answer[50];
	answer[0] = 1;
	answer[1] = 2;
	answer[2] = 3;
	for (int index = 3; index < 50; index++) {
		answer[index] = answer[index - 1] + answer[index - 2];
	}
	int ques;
	while (cin >> ques) {
		cout << setprecision(0) << std::fixed << answer[ques - 1] << endl;
	}
	return 0;
}