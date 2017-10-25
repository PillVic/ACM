#include<iostream>
#include<iomanip>
#include<algorithm>
#include<stdlib.h>

using namespace std;

typedef struct {
	int food;
	int money;
	double value;
}repository;
bool Cheap(repository*a, repository *b) {
	return a->value > b->value;
}
int main() {
	int Money, Number;
	while (cin >> Money >> Number) {
		repository *reps = (repository*)malloc(Number * sizeof(repository));
		for (int index = 0; index < Number; index++) {
			cin >> reps[index].food >> reps[index].money;
			if (reps[index].money == 0) {
				reps[index].value =10000000;
			}
			else {
				reps[index].value = (reps[index].food*1.0) / reps[index].money;
			}
		}
		//sort it
		qsort(reps, Number, sizeof(reps), Cheap);
        // start trade
		int Sum = 0;
		for (int index = 0; index < Number; index++) {
			if (Money > reps[index].money) {
				Money -= reps[index].money;
				Sum += reps[index].food;
			}
			else {
				Sum += reps[index].value*Money;
				break;
			}
		}
		free(reps);
		//Out put the data
		cout << setprecision(3) << std::fixed << Sum << endl;
	}
	return 0;
}



