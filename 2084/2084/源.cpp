#include<iostream>
#include<stdio.h>
#include<stdlib.h>

#define flag -1

using namespace std;

typedef struct {
	int value;
	double sum;
}node;
int getLineBegin(int line) {
	return (line*line + line) / 2;
}

node* buildTower(int height);
void CalSum(node* tower, int height);
double getMaxSum(node* tower, int height);

int main() {
	int Cases;
	while (cin >> Cases) {
		for (int step = 0; step < Cases; step++) {
			int height;
			cin >> height;
			node* tower = buildTower(height);
			CalSum(tower,height);
			double sum = getMaxSum(tower, height);
			cout << sum << endl;
			free(tower);
		}
	}
	return 0;
}

node* buildTower(int height) {
	int number = getLineBegin(height);
	node* tower = (node*)malloc(number * sizeof(node));
	for (int index = 0; index < number; index++) {
		scanf_s("%d", &tower[index].value);
		tower[index].sum = flag;
	}
	return tower;
}

void CalSum(node* tower, int height){
	//Base Case 
	//height=0
	tower[0].sum = tower->value;
	//height=1
	tower[1].sum = tower[0].sum + tower[1].value;
	tower[2].sum = tower[0].sum + tower[2].value;
	if (height <= 2) {
		return;
	}
	for (int line = 2; line < height; line++) {
		int preBegin = getLineBegin(line - 1);
		for (int Position = 0; Position < line; Position++) {
			for (int move = 0; move < 2; move++) {
				int Present = preBegin + Position + line + move;
				double t = tower[preBegin + Position].sum + tower[Present].value;
				if (t > tower[Present].sum) {
					tower[Present].sum = t;
				}
			}
		}
	}
}

double getMaxSum(node* tower, int height) {
	int LastBegin = getLineBegin(height - 1);
	double sum = tower[LastBegin].sum;
	for (int move = 0; move < height; move++) {
		if (sum < tower[LastBegin + move].sum) {
			sum = tower[LastBegin + move].sum;
		}
	}
	return sum;
}