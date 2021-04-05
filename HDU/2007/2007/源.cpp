#include<iostream>

using namespace std;

int main() {
	int a, b;
	while (cin >> a >> b) {
		if (a > b) {
			int t = a;
			a = b;
			b = t;
		}
		int s = 0;
		int t = 0;
		int i = a;
		while (i <= b) {
			if (i %2 == 0) {
				s += i * i;
			}
			else {
				t += i * i*i;
			}
			i++;
		}
		cout << s << " " << t << endl;
	}
	return 0;
}