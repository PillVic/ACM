#include<iostream>
#include<cstdio>
#include<algorithm>
#include<iomanip>

using namespace std;
struct repository{
	int money;
	int food;
	double value;
}reps[1005];
bool Cheap(repository a, repository b){
	return a.value > b.value;
}
int main(){
	int Money, Number;
	while (cin>>Money>>Number){
		if (Money == -1 && Number == -1) {
			break;
		}
		for (int index = 0; index<Number; index++){
			cin >> reps[index].food >> reps[index].money;
			reps[index].value = (reps[index].food*1.0) / reps[index].money;
		}
		sort(reps, reps + Number, Cheap); //按照单位率进行从大到小排序
		double Sum = 0;
		for (int index = 0; index<Number; index++){
			if (reps[index].money <= Money){
				Sum += reps[index].food;
				Money -= reps[index].money;
			}
			else{
				Sum = Sum + Money*reps[index].value;
				break;
			}
		}
		printf("%.3lf\n", Sum);
	}
}