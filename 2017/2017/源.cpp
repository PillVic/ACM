#include<iostream>
#include<string.h>

using namespace std;

int CalNum(char str[]);

int main() {
	char str[100];
	int N;
	cin >> N;
	while (N--) {
		cin >> str;
		cout << CalNum(str) << endl;
	}
	return 0;
}
int CalNum(char str[]) {
	int Num = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (isdigit(str[i])) {
			Num += 1;
		}
	}
	return Num;
}