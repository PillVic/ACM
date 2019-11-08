#include<iostream>
#include<stdlib.h>
#include<algorithm>

using namespace std;

typedef struct {
	int begin;
	int end;
}Program;

bool IsPrior(Program a, Program b) {
	return a.end < b.end;
}

Program* buildTable(int Number);
int CalLength(Program programs[], int Number);
int main() {
	int Number;
	while (cin >> Number) {
		if (Number == 0) {
			break;
		}
		Program* pros = buildTable(Number);
		int length=CalLength(pros, Number);
		cout << length << endl;
		free(pros);
	}
	return 0;
}
Program* buildTable(int Number) {
	Program *pros = (Program*)malloc(Number * sizeof(Program));
	for (int index = 0; index < Number; index++) {
		cin >> pros[index].begin >> pros[index].end;
	}

	sort(pros, pros + Number, IsPrior);
	return pros;
}
int CalLength(Program programs[], int Number) {
	int length = 1;
	Program t = programs[0];
	for (int index = 1; index < Number; index++) {
		if (t.end <= programs[index].begin) {
			length += 1;
			t = programs[index];
		}
	}
	return length;
}
