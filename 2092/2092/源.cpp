#include<stdio.h>
#include<math.h>

//#define scanf_s(A,B,C) scanf(A,B,C)

int main() {
	int sum, product;
	while (scanf_s("%d %d", &sum, &product)!=EOF) {
		if (sum == product && sum == 0) {
			break;
		}
		else {
			int minus =int(sqrt(double(sum * sum - product * 4)));
			int x = (sum + minus) / 2;
			int y = sum - x;
			if (product == x * y&&minus == abs(x - y)) {
				printf("Yes\n");
			}
			else {
				printf("No\n");
			}
		}
	}
	return 0;
}