#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	double answer[20];
	answer[0] = 3;
	answer[1] = 7;
	for (int ques = 2; ques < 20; ques++) {
		//���ǰһ��ѡ������ ����ô����3��ѡ�񣬷���(ѡ�������)ֻ������
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