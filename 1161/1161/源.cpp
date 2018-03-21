#include<iostream>
#include<string.h>
#include<ctype.h>

using namespace std;

int main() {
	static char sentence[1005];
	ios::sync_with_stdio(false);
	while (fgets(sentence, 1004, stdin)) {
		for (auto &i : sentence) {
			i = __ascii_tolower(i);
		}
		cout << sentence;
	}
	return 0;
}