#include<iostream>
#include<algorithm>

using namespace std;

int *buildTeam(int Number);
void Fight(int Hdu[], int Japan[], int Number);
int main() {
	int Number;
	while (cin >> Number) {
		if (Number == 0) {
			break;
		}
		int *Hdu = buildTeam(Number);
		int *Japan = buildTeam(Number);
		Fight(Hdu, Japan, Number);
		free(Hdu);
		free(Japan);
	}
}
int* buildTeam(int Number) {
	int *team = (int*)malloc(Number * sizeof(int));
	for (int index = 0; index < Number; index++) {
		cin >> team[index];
	}

	sort(team, team+Number);
	
	return team;
}
void Fight(int Hdu[], int Japan[], int Number) {
	int hdu = 0;
	int japan = 0;
	for (int index = 0; index < Number; index++) {
		if (Hdu[index] > Japan[index]) {
			hdu += 2;
		}
		else if (Hdu[index] == Japan[index]) {
			hdu += 1;
			japan += 1;
		}
		else {
			japan += 2;
		}
	}
	cout << hdu << " vs " << japan << endl;
}
