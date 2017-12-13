/*
第一个下标表示输入第n个骨头 第二个下标表示背包的体积
状态方程 f[i][j] = max{f[i-1][j],f[i-1][j-c]+v[i]}
显然可以用二维矩阵进行计算状态方程
由于只用到前一行，所以可以直接使用一维矩阵进行简化来减少空间开支
*/

#include<stdio.h>  
#include<iostream>
#include<string.h>  

#define M 1009  

using namespace std;
typedef struct pack
{
	int cost;
	int value;
}PACK;
int main(){
	int Cases, Number, Volumes, i, j;
	int f[M];
	PACK packs[M];
	//scanf_s("%d", &Cases);
	cin >> Cases;
	while (Cases--){
		//scanf("%d%d", &Number, &Volumes);
		cin >> Number >> Volumes;
		memset(f, 0, sizeof(f));
		for (i = 1; i <= Number; i++) {
			//scanf("%d", &packs[i].value);
			cin >> packs[i].value;
		}
		for (i = 1; i <= Number; i++) {
			//scanf("%d", &packs[i].cost);
			cin >> packs[i].cost;
		}
		for (i = 1; i <= Number; i++) {
			for (j = Volumes; j >= packs[i].cost; j--) {
				if (f[j] < f[j - packs[i].cost] + packs[i].value) {
					f[j] = f[j - packs[i].cost] + packs[i].value;
				}
			}
		}
		printf("%d\n", f[Volumes]);
	}
	return 0;
}
