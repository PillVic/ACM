#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

//道路建模
typedef struct {
	int town1;
	int town2;
	int cost;
}road;

inline bool IsNearer(road a, road b) { return a.cost < b.cost; }

typedef int SetElement;
typedef SetElement *Set;

inline SetElement max(SetElement e1, SetElement e2) { return e1 > e2 ? e1 : e2; }
inline SetElement min(SetElement e1, SetElement e2) { return e1 < e2 ? e1 : e2; }

static int ElementNumber;
Set BuildSet(int Number) {
	Set S = (SetElement*)malloc(Number * sizeof(SetElement));
	ElementNumber = Number;
	for (int i = 0; i < ElementNumber; i++) {
		S[i] = i + 1;
	}
	return S;
}
SetElement Find(Set S, SetElement e1) {
	return S[e1 - 1];
}
void Merge(Set S, SetElement e1, SetElement e2) {
	SetElement t = max(Find(S, e1), Find(S, e2));
	SetElement m = min(Find(S, e1), Find(S, e2));
	for (int i = 0; i < ElementNumber; i++) {
		if (S[i] == t) {
			S[i] = m;
		}
	}

}

int main() {
	int townNumber;
	while (cin >> townNumber) {
		if (townNumber == 0) {
			break;
		}
		//input data
		Set towns = BuildSet(townNumber);
		int roadNumber = townNumber * (townNumber - 1) / 2;
		road* roads = (road*)malloc(roadNumber * sizeof(road));
		int done;
		for (int i = 0; i < roadNumber; i++) {
			scanf_s("%d%d%d%d", 
				&roads[i].town1, &roads[i].town2,&roads[i].cost, 
				&done);
			if (done == 1) {
				roads[i].cost = 0;
			}
		}
		//sort data
		sort(roads, roads+roadNumber, IsNearer);
		//Kruskal
		int Cost = 0;
		for (int i = 0; i < roadNumber; i++) {
			if (Find(towns, roads[i].town1) != Find(towns, roads[i].town2)) {
				Merge(towns, roads[i].town1, roads[i].town2);
				Cost += roads[i].cost;
			}
		}
		printf("%d\n", Cost);
		//free memory
		free(towns);
		free(roads);
	}
	return 0;
}