#include<iostream>

using namespace std;

int Climb(int stage[], int N);
int main() {
	int N;
	while (cin >> N) {
		if (N == 0) {
			return 0;
		}
		int *stage;
		stage = new int[N];
		for (int index = 0; index < N; index++) {
			cin >> stage[index];
		}
		cout << Climb(stage, N) << endl;;
	}
	return 0;
}
int Climb(int stage[], int N) {
	int time = 0;
	int position = 0;
	int up = 6; int down = 4; int wait = 5;
	for (int index = 0; index < N; index++) {
		if (position > stage[index]) {
			time += (position - stage[index])*down;
			position = stage[index];
		}
		else {
			time += (stage[index] - position)*up;
			position = stage[index];
		}
		time += 5;
	}
	return time;
}