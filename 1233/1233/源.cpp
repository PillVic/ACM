#include<iostream>
#include<stdlib.h>
#include<algorithm>

#define MIN(A,B) A<B?A:B
#define MAX(A,B) A>B?A:B

using namespace std;

typedef struct {
	int town1;
	int town2;
	int distance;
}road;

typedef int SetType;
typedef SetType *Set;
bool IsNearer(void *a, void*b) {
	return (*(road*)a).distance < (*(road*)b).distance;
}

Set BuildSet(int Numeber);
SetType Find(Set S, SetType e);
void Merge(Set S, SetType e1, SetType e2);
void DestroySet(Set S);
static int length;

int main() {
	int towns;
	while (cin >> towns) {
		if (towns == 0) {
			break;
		}
		Set cities = BuildSet(towns);
		int lines = towns * (towns - 1) / 2;
		road *roads = (road*)malloc(lines * sizeof(road));
		for (int i = 0; i < lines; i++) {
			cin >> roads[i].town1 >> roads[i].town2 >> roads[i].distance;
		}
		sort(roads, roads + lines, IsNearer);

	}
	return 0;
}

Set BuildSet(int Number) {
	Set S = (SetType*)malloc(Number * sizeof(SetType));
	length = Number;
	for (int i = 0; i < Number; i++) {
		S[i] = i + 1;
	}
	return S;
}
SetType Find(Set S, SetType e) {
	return S[e - 1];
}
void Merge(Set S, SetType e1, SetType e2) {

}