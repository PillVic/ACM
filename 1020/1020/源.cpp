#include<iostream>
#include<string>
#include<string.h>
#include<vector>

using namespace std;

typedef struct {
	int time;
	char c;
}chart;

int main() {
	int Cases;
	std::ios::sync_with_stdio(false);
	cin >> Cases;
	vector <chart> v;
	while (Cases--) {
		v.clear();
		chart a;
		static char s[100000];
		cin >> s;
		a.c = s[0];
		a.time = 1;
		v.push_back(a);
		int i = 1;
		int length = strlen(s);
		while (i<length) {
			a.c = s[i++];
			if (v[v.size() - 1].c == a.c) {
				v[v.size() - 1].time += 1;
			}
			else {
				a.time = 1;
				v.push_back(a);
			}
		}
		for (const auto &i : v) {
			if (i.time == 1) {
				cout << i.c;
			}
			else {
				cout << i.time << i.c;
			}
		}
		cout << endl;
	}
	return 0;
}
