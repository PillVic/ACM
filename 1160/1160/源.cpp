#include<iostream>
#include<algorithm>

using namespace std;

typedef struct {
	int weight;
	int speed;
}mouse;

bool IsFitter(mouse a, mouse b) {
	return a.weight < b.weight;
}

int main() {

	return 0;
}