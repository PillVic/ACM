/*
第一个下标表示输入第n个食物 第二个下标表示背包的卡路里
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
inline double max(double a, double b) { return a > b ? a : b; }
static FOOD foods[M];
static double f[100001];
int main() {
	int Kinds;
	while (cin>>Kinds) {
		//初始化
		memset(f, 0, M);
		//输入数据
		for (int index = 0; index < Kinds; index++) {
			cin >> foods[index].happiness >> foods[index].calories;
		}
		int Limit;
		cin >> Limit;
		//开始计算该状态方程
		for (int i = 0; i < Kinds; i++) {
			for (int j = foods[i].calories; j <=Limit; j++) {
				f[j] = max(f[j], f[j-foods[i].calories] + foods[i].happiness);
			}
		}
		cout << f[Limit] << endl;
	}
	return 0;
}