#include<iostream>
#include<stdlib.h>
#include<algorithm>

#define MIN(x,y) x<y?x:y
using namespace std;

//Set implement
typedef int *Set;
typedef int SetType;
typedef int ElementType;

Set BuildSet(int Number);
void SetUnion(Set s, SetType e1, SetType e2);
SetType Find(Set S, SetType e);
static int length;
void Destroy(Set S);

int main() {
	int towns, roads;
	while (cin >> towns >> roads) {
		if (towns == 0) {
			break;
		}
		Set S = BuildSet(towns);
		for (int road = 0; road < roads; road++) {
			SetType city1, city2;
			cin >> city1 >> city2;
			SetUnion(S, city1, city2);
		}
		sort(S, S + towns);
		SetType flag = S[0];
		int num = 1;
		for (int index = 0; index < towns; index++) {
			if (flag != S[index]) {
				num += 1;
				flag = S[index];
			}
		}
		cout << num - 1 << endl;
		Destroy(S);
	}
	return 0;
}

Set BuildSet(int Number) {
	Set s = (SetType*)malloc(Number * sizeof(SetType));
	length = Number;
	for (int i = 0; i < length; i++) {
		s[i] = i + 1;
	}
	return s;
}
void SetUnion(Set s, SetType e1, SetType e2) {
	SetType newS = MIN(s[e1 - 1], s[e2 - 1]);
	SetType oldS = s[e1 - 1] + s[e2 - 1] - newS;
	for (int i = 0; i < length; i++) {
		if (s[i] == oldS) {
			s[i] = newS;
		}
	}
}
SetType Find(Set s, SetType e) {
	return s[e - 1];
}
void Destroy(Set S) {
	free(S);
	S = NULL;
}
