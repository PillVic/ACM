#include<iostream>
#include<stdlib.h>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	int Case;
	int Number;
	string result[2] = { "yes","no" };
	while (cin >> Case) {
		for (int step = 0; step < Case; step++) {
			cin >> Number;
			int *degree = (int*)malloc(Number * sizeof(Number));
			for (int index = 0; index < Number; index++) {
				cin>>degree[index];
			}

			sort(degree, degree + Number);

		}
	}
	return 0;
}