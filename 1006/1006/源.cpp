#include<iostream>
#include<iomanip> 
#include<math.h>

#define FullTime 86400

#define SecMove 360/(60.0)
#define MinMove 360/(60*60.0)
#define HouMove 360/(12.0*60.0*60.0)

using namespace std;

int CalFunTime(int D);

int main() {
	int D;
	while (cin >> D) {
		if (D == -1) {
			return 0;
		}
		else {
			cout << setprecision(3) <<fixed
				<< 100.0* CalFunTime(D)/FullTime*1.0<<endl;
		}
	}
	return 0;
}
//输入数据90后结果不正确（应该是6.251
int CalFunTime(int D) {
	int Time = 0;
	double Hourhand = 0;
	double SecHand = 0;
	double MinHand = 0;
	int FunTime = 0;
	while (Time < FullTime) {
		if (Hourhand >= 360) {
			Hourhand -= 360;
		}
		if (SecHand >= 360) {
			SecHand -= 360;
		}
		if (MinHand >= 360) {
			MinHand -= 360;
		}
		Hourhand += HouMove;
		MinHand += MinMove;
		SecHand += SecMove;
		if(abs(Hourhand-MinHand)>D
			&&abs(Hourhand-SecHand)>D
			&&abs(MinHand - SecHand)>D) {
			FunTime += 1;
		}
		Time += 1;
	}
	return FunTime;
}

