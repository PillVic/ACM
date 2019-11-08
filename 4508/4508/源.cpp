/*
��һ���±��ʾ�����n��ʳ�� �ڶ����±��ʾ�����Ŀ�·��
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
inline double max(double a, double b) { return a > b ? a : b; }
static FOOD foods[M];
static double f[100001];
int main() {
	int Kinds;
	while (cin>>Kinds) {
		//��ʼ��
		memset(f, 0, M);
		//��������
		for (int index = 0; index < Kinds; index++) {
			cin >> foods[index].happiness >> foods[index].calories;
		}
		int Limit;
		cin >> Limit;
		//��ʼ�����״̬����
		for (int i = 0; i < Kinds; i++) {
			for (int j = foods[i].calories; j <=Limit; j++) {
				f[j] = max(f[j], f[j-foods[i].calories] + foods[i].happiness);
			}
		}
		cout << f[Limit] << endl;
	}
	return 0;
}