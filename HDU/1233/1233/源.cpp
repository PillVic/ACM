#include<iostream>
#include<stdlib.h>
#include<algorithm>

using namespace std;

/*
计算通路的最小开销即求最小生成树
使用Kruskal算法，生成最小生成树，
同时将接受的边的开销累加，即为答案
*/

typedef struct {
	int town1;
	int town2;
	int distance;
}road;

typedef int SetElement;
typedef SetElement *Set;

inline SetElement min(SetElement e1, SetElement e2) { return e1 < e2 ? e1 : e2; }
inline SetElement max(SetElement e1, SetElement e2) { return e1 > e2 ? e1 : e2; }

inline bool IsNearer(road a, road b) {
	return a.distance < b.distance;
}

static int SetNumber;

inline Set BuildSet(int Numeber);
inline SetElement Find(Set S, SetElement e);
void Merge(Set S, SetElement e1, SetElement e2);
inline void DestroySet(Set S);


int main() {
	int townNum;
	while (cin >> townNum) {
		if (townNum == 0) {
			break;
		}
		if (townNum == 1) {
			cout << 0 << endl;
			continue;
		}
		//input the data
		Set towns = BuildSet(townNum);
		int roadNum = townNum * (townNum - 1) / 2;
		road *roads = (road*)malloc(roadNum * sizeof(road));
		for (int i = 0; i < roadNum; i++) {
			cin >> roads[i].town1 >> roads[i].town2 >> roads[i].distance;
		}
		//sort data
		sort(roads, roads + roadNum, IsNearer);
		//Kruskal algrithm
		double cost = roads[0].distance;
		Merge(towns, roads[0].town1, roads[0].town2);
		for (int index = 1; index < roadNum; index++) {
			int town1 = roads[index].town1;
			int town2 = roads[index].town2;
			if(Find(towns,town1)!=Find(towns,town2)){
				Merge(towns,town1, town2);
				cost += roads[index].distance;
			}
		}
		cout << cost << endl;
		DestroySet(towns);
		free(roads);
	}
	return 0;
}

Set BuildSet(int Number) {
	Set S = (SetElement*)malloc(Number * sizeof(SetElement));
	SetNumber = Number;
	for (int i = 0; i < Number; i++) {
		S[i] = i + 1;
	}
	return S;
}
SetElement Find(Set S, SetElement e) {
	return S[e - 1];
}
void Merge(Set S, SetElement e1, SetElement e2) {
	if (Find(S, e1) == Find(S, e2)) {
		return;
	}
	else {
		SetElement t = min(Find(S, e1), Find(S, e2));
		SetElement m = max(Find(S, e1), Find(S, e2));
		for (int index = 0; index < SetNumber; index++) {
			if (S[index] == t) {
				S[index] = m;
			}
		}
	}
}
void DestroySet(Set S) {
	free(S);
}