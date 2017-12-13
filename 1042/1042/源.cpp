#include<stdio.h>


int main() {
	int N;
	while (scanf_s("%d",&N)) {
		int Number[1000];
		for (int i = 0; i < 1000; i++) {
			Number[i] = 0;
		}		
		Number[0] = 1;
		int length = 1;
		for (int i = 1; i <= N; i++) {
			for (int index = 0; index < length;index++) {
				int t = Number[index] * i;
				Number[index] = t % 10;
				Number[index + 1] = t / 10;
				if (t > 10) {
					length++;
				}
			}
		}
		int head = 999;
		while (true) {
			if (Number[head] != 0) {
				break;
			}
			else {
				head--;
			}
		}
		while (head >= 0) {
			printf("%d", Number[head]);
			head--;
		}
		printf("\n");
	}
	return 0;
}