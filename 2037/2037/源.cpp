#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct {
	int begin;
	int end;
}Program;
int main() {
	int Number;
	while (cin >> Number) {
		Program *pros = (Program*)malloc(Number * sizeof(Number));

	}
	return 0;
}