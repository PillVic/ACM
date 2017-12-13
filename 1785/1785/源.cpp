#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>


using namespace std;
/*
通过叉积时的正负性，来定义偏序，从而完成排序
*/

typedef struct {
	double x;
	double y;
}node;

inline double crossProduct(node a, node b) {
	return a.x*b.y - b.x * a.y;
}

bool IsPrior(node a, node b) {
	return crossProduct(a, b) >= 0;
}

int main() {
	int Number;
	while (cin >> Number) {
		if (Number == -1) {
			break;
		}
		//input data
		node *members = (node*)malloc(sizeof(node));
		for (int index = 0; index < Number; index++) {
			cin >> members[index].x >> members[index].y;
		}
		//sort the data
		sort(members, members+Number,IsPrior);
		//output the sorted data
		for (int index = 0; index+1 < Number; index++) {
			printf("%.1f %.1f ", members[index].x, members[index].y);
		}
		printf("%.1f %.1f\n", members[Number - 1].x, members[Number - 1].y);
		//free memory

	}
	return 0;
}