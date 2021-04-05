#include<stdio.h>
#include<stdlib.h>

#define scanf(A,B) scanf_s(A,B)
/*
ÊýËþÎÊÌâ

*/
typedef struct {
	int value;
	int sum;
}Node;

Node tower[101][105];

inline int max(int a, int b) { return a > b ? a : b; }

void InputTower(Node tower[][105], int Height);
int CalSum(Node tower[][105], int Height);

int main() {
	int Cases;
	scanf("%d", &Cases);
	while (Cases--) {
		int Height;
		scanf("%d", &Height);
		InputTower(tower, Height);
		printf("%d\n", CalSum(tower, Height));
	}
	return 0;
}

void InputTower(Node tower[][105], int Height) {
	for (int y = 0; y < Height; y++) {
		for (int x = 0; x <= y; x++) {
			scanf("%d", &tower[y][x]);
			tower[y][x].sum = INT_MIN;
		}
	}
}

int  CalSum(Node tower[][105], int Height) {
	//Base Case
	tower[0][0].sum = tower[0][0].value;
//	tower[1][0].sum = tower[0][0].sum + tower[1][0].value;
//	tower[1][1].sum = tower[0][0].sum + tower[1][1].value;
	for (int y = 0; y < Height-1; y++) {
		for (int x = 0; x <= y; x++) {
			tower[y + 1][x].sum = max(tower[y+1][x].sum,
									tower[y][x].sum + tower[y + 1][x].value);
			tower[y + 1][x + 1].sum = max(tower[y + 1][x+1].sum, 
									tower[y][x].sum + tower[y + 1][x+1].value);
		}
	}
	int t = tower[Height - 1][0].sum;
	for (int i = 0; i < Height; i++) {
		t = max(t, tower[Height - 1][i].sum);
	}
	return t;
}