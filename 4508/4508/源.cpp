/*
第一个下标表示输入第n个骨头 第二个下标表示背包的体积
状态方程 f[i][j] = max{f[i-1][j],f[i-1][j-c]+v[i]}
显然可以用二维矩阵进行计算状态方程
由于只用到前一行，所以可以直接使用一维矩阵进行简化来减少空间开支
*/

#include<stdio.h>  
#include<iostream>
#include<string.h>  

#define M 200 

using namespace std;
typedef struct food{
	int calories;
	int happiness;
}FOOD;

inline int max(int a, int b) { return a > b ? a : b; }

static FOOD foods[M];

static double f[100001];

int main() {
	int Cases;
	int Kinds;
	while (cin>>Kinds) {
		memset(f, 0, M);
		for (int index = 0; index < Kinds; index++) {
			//scanf_s("%d%d", foods[index].happiness, foods[index].calories);
			cin >> foods[index].happiness >> foods[index].calories;
		}
		int Limit;
		//scanf_s("%d", &Limit);
		cin >> Limit;
		//开始计算该状态方程
		for (int i = 0; i < Kinds; i++) {
			for (int j = foods[i].calories; j <=Limit; j++) {
				f[j] = max(f[j], f[j-foods[i].calories] + foods[i].happiness);
			}
		}
		//printf("%d\n", f[Limit]);
		cout << f[Limit] << endl;
	}
	return 0;
}