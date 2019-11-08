#include<stack>
#include<iostream>

using namespace std;

int main() {
	stack<char> s;
	int Number;
	cin >> Number;
	char i = getchar();
	while (Number--) {
		while (true) {
			char t = getchar();
			while (t != '\n'&&t != ' ') {
				s.push(t);
				t = getchar();
			}
			while (!s.empty()) {
				char c = s.top();
				cout << c;
				s.pop();
			}
			if (t == ' ') {
				cout << ' ';
				continue;
			}
			else {
				cout << endl;
				break;
			}
		}
	}
	return 0;
}