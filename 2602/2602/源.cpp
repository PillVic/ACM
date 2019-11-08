/*
��һ���±��ʾ�����n����ͷ �ڶ����±��ʾ���������
״̬���� f[i][j] = max{f[i-1][j],f[i-1][j-c]+v[i]}
��Ȼ�����ö�ά������м���״̬����
����ֻ�õ�ǰһ�У����Կ���ֱ��ʹ��һά������м������ٿռ俪֧
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
