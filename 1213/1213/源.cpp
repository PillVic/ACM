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
	int Cases;
	while (cin >> Cases) {
		for (int i = 0; i < Cases; i++) {
			int Number;
			int lines;
			cin >> Number >> lines;
			Set	S = BuildSet(Number);
			for (int line = 0; line < lines; line++) {
				SetType e1, e2;
				cin >> e1 >> e2;
				SetUnion(S, e1, e2);
			}
			sort(S, S + length);
			SetType start = S[0];
			int num = 1;
			for (int i = 0; i < length; i++) {
				if (S[i] != start) {
					num += 1;
					start = S[i];
				}
			}
			cout << num<< endl;
			Destroy(S);
		}
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
	SetType newS = MIN(s[e1-1], s[e2-1]);
	SetType oldS = s[e1-1] + s[e2-1] - newS;
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
