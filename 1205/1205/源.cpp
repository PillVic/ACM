#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int Group;
	int Kind;
	while (cin >> Group) {
		for(int group = 0; group < Group; group++){
			cin >> Kind;
			int *Candy = (int*)malloc(Kind * sizeof(int));
			for (int index = 0; index < Kind; index++) {
				cin >> Candy[index];
			}
			sort(Candy, Candy + Kind);
			double Sum = 0;
			for (int index = 0; index < Kind-1; index++) {
				Sum += Candy[index];
			}
			if (Sum+1 >= Candy[Kind - 1]) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
			free(Candy);
		}
	}
	return 0;
}
