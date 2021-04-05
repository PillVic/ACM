#include<iostream>
#include<iomanip>
#include<stdlib.h>

using namespace std;
/*
利用叉积的有向面积特性来计算多边形的面积
*/

typedef struct {
	int x;
	int y;
}node;

inline double crossProduct(node a, node b) {
	return a.x* b.y - a.y*b.x;
}

int main() {
	int nodeNumber;
	while (cin >> nodeNumber) {
		if (nodeNumber == 0) {
			break;
		}
		//input data
		node * nodes = (node*)malloc(nodeNumber * sizeof(node));
		for (int i = 0; i < nodeNumber; i++) {
			cin >> nodes[i].x >> nodes[i].y;
		}
		double sumArea = 0;
		for (int index = 0; (index+1) < nodeNumber; index++) {
			sumArea += crossProduct(nodes[index], nodes[index + 1]);
		}
		sumArea += crossProduct(nodes[nodeNumber - 1], nodes[0]);
		sumArea /= 2;
		cout << setprecision(1) << std::fixed << sumArea << endl;
		free(nodes);
	}
	return 0;
}