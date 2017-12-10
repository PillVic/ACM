/*
��һ���±��ʾ�����n����ͷ �ڶ����±��ʾ���������
״̬���� f[i][j] = max{f[i-1][j],f[i-1][j-c]+v[i]}
��Ȼ�����ö�ά������м���״̬����
����ֻ�õ�ǰһ�У����Կ���ֱ��ʹ��һά������м������ٿռ俪֧
*/

#include<stdio.h>  
#include<string.h>  
#define M 1009  

typedef struct pack
{
	int cost;
	int value;
}PACK;
int main(){
	int Cases, Number, Volumes, i, j;
	int f[M];
	PACK packs[M];
	scanf_s("%d", &Cases);
	while (Cases--){
		scanf_s("%d%d", &Number, &Volumes);
		memset(f, 0, sizeof(f));
		for (i = 1; i <= Number; i++) {
			scanf_s("%d", &packs[i].value);
		}
		for (i = 1; i <= Number; i++) {
			scanf_s("%d", &packs[i].cost);
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
