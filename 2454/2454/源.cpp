/*
整数序列的可图性判定
递归性：任何一个图删除任何一个点，及其相关边后仍为图
*/
#include<iostream>
#include<algorithm>
#include<stdlib.h>

using namespace std;

int* getSeq(int length);
bool IsGraph(int* seq, int length);
bool Judge(int a, int b) { return a > b; }
int main() {
	int Cases;
	cin >> Cases;
	while (Cases--) {
		int length;
		cin >> length;
		int* s = getSeq(length);
		sort(s, s + length,Judge);
		if (s[0] < 0) {
			cout << "no" << endl;
			continue;
		}
		int i = 0;
		while (s[i] == 0) {
			i++;
			length--;
		}
		if (IsGraph(s+i, length)) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
		//free(s);
	}

	return 0;
}
int* getSeq(int length) {
	int *s = (int*)malloc(length * sizeof(int));
	for (int index = 0; index < length; index++) {
		cin >> s[index];
	}
	return s;
}
bool IsGraph(int *seq, int length) {
	if (seq[0] > length - 1) {
		return false;
	}
	while(seq[0]>0){
		for (int t = 0; t < seq[0]; t++) {
			seq[t+1] -= 1;
		}
		seq[0] = 0;
		sort(seq, seq + length, Judge);
	}
	for (int i = 0; i < length; i++) {
		if (seq[i] != 0) {
			return false;
		}
	}
	return true;
}