#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	double answer[1000];
	answer[0] = 1;
	answer[1] = 2;
	answer[2] = 4;
	answer[3] = 7;
	for (int index = 4; index < 1000; index++) {
		answer[index] = answer[index - 1] +answer[index-2]+ answer[index - 4];
	}
	int ques;
	while (cin >> ques) {
		cout << setprecision(0) << std::fixed << answer[ques - 1] << endl;
	}
	return 0;
}