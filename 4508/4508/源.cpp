/*
��һ���±��ʾ�����n����ͷ �ڶ����±��ʾ���������
״̬���� f[i][j] = max{f[i-1][j],f[i-1][j-c]+v[i]}
��Ȼ�����ö�ά������м���״̬����
����ֻ�õ�ǰһ�У����Կ���ֱ��ʹ��һά������м������ٿռ俪֧
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
		//��ʼ�����״̬����
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