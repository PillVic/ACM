#include<iostream>
#include<algorithm>
using namespace std;



//实现并查集
typedef int *Set;
typedef int setElement;
typedef int Position;

static int ElementNumber;

inline setElement max(setElement a, setElement b) { return a > b ? a : b; }
inline setElement min(setElement a, setElement b) { return a < b ? a : b; }

inline Set buildSet(int Number);
inline Position Find(Set S, setElement e1);
void Merge(Set S, setElement e1, setElement e2);
inline void Destroy(Set S);

int main() {
	int Cases;
	cin >> Cases;
	while (Cases--) {
		int Number;
		cin >> Number;
		Set S = buildSet(Number);
		int lines;
		cin >> lines;
		for (int line = 0; line < lines; line++) {
			setElement e1, e2;
			cin >> e1 >> e2;
			Merge(S, e1, e2);
		}
		//Calculate the Set Number
		sort(S, S + ElementNumber);
		int SetNumber = 1;
		setElement t = S[0];
		for (int index = 1; index < ElementNumber; index++) {
			if (t != S[index]) {
				SetNumber += 1;
				t = S[index];
			}
		}
		cout << SetNumber << endl;
		Destroy(S);
	}
	return 0;
}
Set buildSet(int Number) {
	Set S = new setElement[Number];
	ElementNumber = Number;
	for (int i = 0; i < Number; i++) {
		S[i] = i + 1;
	}
	return S;
}
Position Find(Set S, setElement e) {
	return S[e-1];
}

void Merge(Set S, setElement e1, setElement e2) {
	if (Find(S, e1) == Find(S, e2)) {
		return;
	}
	else {
		setElement t = max(Find(S,e1), Find(S,e2));
		setElement m = min(Find(S, e1), Find(S, e2));
		for (int index = 0; index < ElementNumber; index++) {
			if (S[index] == t) {
				S[index] = m;
			}
		}
	}
}
void Destroy(Set S) {
	delete S;
}
