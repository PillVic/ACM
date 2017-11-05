#include<iostream>
#include<iomanip>
#include<algorithm>

using namespace std;

typedef struct {
	int price;
	int content;
}Shop;

int Cheap(const void *a, const void *b);
void InputShop(Shop shops[], int Kind);
double Buy(int Money,Shop shops[], int Kind);

int main() {
	Shop shops[1000];
	int Case;
	cin >> Case;
	for (int step = 0; step < Case; step++) {
		int money, kind;
		cin >> money >> kind;
		//InputShop(shops, kind);
		for (int i = 0; i < kind; i++) {
			cin >> shops[i].price >> shops[i].content;
		}
		qsort(shops, kind, sizeof(Shop), Cheap);
		double sum = 0;
		for (int i = 0; i < kind; i++) {
			if (money >= shops[i].price*shops[i].content) {
				money -= shops[i].price*shops[i].content;
				sum += shops[i].content;
			}
			else {
				sum += money*1.0 / shops[i].price;
				break;
			}
		}
		cout << setiosflags(ios::fixed) << setprecision(2) 
			<< sum << endl;
	}
	return 0;
}

	int Cheap(const void *a, const void *b) {
		return ((Shop*)a)->price > ((Shop*)b)->price;
	}
	void InputShop(Shop shops[], int Kind) {
		for (int i = 0; i < Kind; i++) {
			cin >> shops[i].price >> shops[i].content;
		}
	}
	double Buy(int Money,Shop shops[], int Kind) {
		double sum = 0;
		for (int index = 0; index < Kind; index++) {
			if (Money >= shops[index].price*shops[index].content) {
				Money -= shops[index].price*shops[index].content;
				sum += shops[index].content;
			}
			else {
				sum += Money*1.0 / shops[index].price;
				break;
			}
		}
		return sum;
}
#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
struct Rice
{
	int Price, Content;
}SHOPS[1000];
bool cmp(Rice&a, Rice &b)
{
	return a.Price < b.Price;
}
int main(void)
{
	int Case, Money, Kind;
	double Sum;
	cin >> Case;
	while (Case--)
	{
		Sum = 0.0;
		cin >> Money >> Kind;
		for (int index = 0; index < Kind; index++){
			cin >> SHOPS[index].Price >> SHOPS[index].Content;
		}
		sort(SHOPS, SHOPS + Kind, cmp);
		for (int i = 0; i < Kind; i++){
			if (Money >= SHOPS[i].Price*SHOPS[i].Content){
				Sum += SHOPS[i].Content;
				Money -= SHOPS[i].Price*SHOPS[i].Content;
			}
			else{
				Sum += Money*1.0 / SHOPS[i].Price;
				break;
			}
		}
		cout << setiosflags(ios::fixed) << setprecision(2) << Sum << endl;
	}
	return 0;
}
