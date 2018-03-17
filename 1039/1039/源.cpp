#include<iostream>
#include<string.h>

using namespace std;

bool IsPronunce(char s[]);
int main() {
	std::ios::sync_with_stdio(false);
	static char pswd[40];
	while (cin >> pswd) {
		if (strcmp(pswd,"end")==0) {
			break;
		}
		if (IsPronunce(pswd)) {
			cout << "<" << pswd << ">" 
				<< " is acceptable." 
				<< endl;
		}
		else {
			cout << "<" << pswd << ">" 
				<< " is not acceptable." 
				<< endl;
		}
	}
	return 0;
}
const char vowl[] = "aeiou";

static bool IsVowl(char c) {
	return strchr(vowl, c) != NULL&&c!='\0';
}
bool IsPronunce(char pswd[]) {
	int length = strlen(pswd);
	int vowlt = 0;
	for (int i = 0; i < length; i++) {
		if (i + 2 < length) {
			if (IsVowl(pswd[i])==IsVowl(pswd[i+1])
				&&IsVowl(pswd[i+1])==IsVowl(pswd[i+2])) {
				return false;
			}
		}
		if (i + 1 < length) {
			if (pswd[i] == pswd[i + 1]) {
				if (pswd[i] != 'e' && pswd[i] != 'o') {
					return false;
				}
			}
		}
		if (IsVowl(pswd[i])) {
			vowlt += 1;
		}
	}
	return vowlt != 0;
}