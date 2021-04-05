#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

typedef vector<string> sentence;

static sentence v;

void buildDict(sentence &v);
sentence findWord(const string &word,const sentence &dict);
bool MySame(string s, string t);
int main() {
	buildDict(v);
	string word;
	std::ios::sync_with_stdio(false);
	while (cin >> word && word != "XXXXXX") {
		sentence s = findWord(word,v);
		if (s.empty()) {
			cout << "NOT A VALID WORD" << endl;
		}
		else {
			for (const auto&i : s) {
				cout << i << endl;
			}
		}
		cout << "******" << endl;
	}
	return 0;
}
void buildDict(sentence &v) {
	string s;
	std::ios::sync_with_stdio(false);
	while (cin >> s && s != "XXXXXX") {
		v.push_back(s);
	}
	sort(v.begin(), v.end());
}
sentence findWord(const string &word,const sentence &dict) {
	sentence s;
	for (const auto &dw : dict) {
		if (MySame(dw, word) ){
			s.push_back(dw);
		}
	}
	return s;
}
bool MySame(string s, string t) {
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	return s == t;
}