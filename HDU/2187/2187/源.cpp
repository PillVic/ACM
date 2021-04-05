#include<iostream>
#include<iomanip>
#include<algorithm>

using namespace std;

typedef struct {
	int perCost;
	int capacity;
}shop;

bool IsCheap(shop a, shop b) {
	return a.perCost < b.perCost;
}
shop* buildTable(int Kinds);
double buyRice(int Money, shop shops[], int shopsNumber);
int main() {
	int Cases;
	while (cin >> Cases) {
		for (int step = 0; step < Cases; step++) {
			int Money, shopsNumber;
			cin >> Money >> shopsNumber;
			shop* shops = buildTable(shopsNumber);
			double sum = buyRice(Money, shops, shopsNumber);
			free(shops);
			cout << setprecision(2) << std::fixed << sum<<endl;
		}
	}
	return 0;
}
shop* buildTable(int Kinds) {
	shop* shops = (shop*)malloc(Kinds * sizeof(shop));
	
	for (int index = 0; index < Kinds; index++) {
		cin >> shops[index].perCost >> shops[index].capacity;
	}

	sort(shops, shops + Kinds, IsCheap);

	return shops;
}

double buyRice(int Money, shop shops[], int shopNumber) {
	double sum = 0;
	double totalCost;
	for (int index = 0; index < shopNumber; index++) {
		totalCost = shops[index].capacity*shops[index].perCost;
		if (Money > totalCost) {
			sum += shops[index].capacity;
			Money -= totalCost;
		}
		else {
			sum += Money*1.0 / shops[index].perCost;
			break;
		}
	}
	return sum;
}
