#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	double answer[50];
	answer[0] = 1;
	answer[1] = 2;
	//归纳为0到任意位置的计算
	for (int index = 2; index < 50; index++) {
		answer[index] = answer[index - 1]+answer[index-2];
	}
	int Number;
	int a, b;
	while (cin >> Number) {
		for (int step = 0; step < Number; step++) {
			cin >> a >> b;
			cout << setprecision(0) << std::fixed << answer[b - a - 1] << endl;
		}
	}
	return 0;
}