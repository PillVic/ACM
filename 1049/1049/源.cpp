#include<iostream>

using namespace std;

int Climb(int minutes,int deepth, int up, int down);
int main() {
	int deepth, up, down;
	while (cin >> deepth >> up >> down) {
		if (deepth == 0 && up == 0 && down == 0) {
			return 0;
		}
		cout << Climb(0,deepth, up, down)<<endl;
	}
	return 0;
}
int Climb(int minutes,int deepth, int up, int down) {
	if (deepth <= 0) {
		return minutes;
	}
	else if (minutes % 2 != 0) {
		return Climb(minutes + 1, deepth + down, up, down);
	}
	else {
		return Climb(minutes + 1, deepth - up, up, down);
	}
}