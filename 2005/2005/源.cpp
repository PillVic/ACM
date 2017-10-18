#include<stdio.h>
#include<time.h>

bool IsLeapYear(int year);
int CalDay(tm Date);
int main() {
	tm Date;
	while (scanf_s("%d/%d/%d", &Date.tm_year, &Date.tm_mon, &Date.tm_mday)!=-1) {
		printf("%d\n", CalDay(Date));
	}
	return 0;
}
bool IsLeapYear(int year) {
	if (year % 400 == 0) {
		return true;
	}
	else if (year % 4 == 0 && year % 100 != 0) {
		return true;
	}
	return false;
}
int CalDay(tm Date) {
	static int Month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int Sum = 0;
	for (int i = 0; i < Date.tm_mon-1; i++) {
		Sum += Month[i];
	}
	Sum += Date.tm_mday;
	if (IsLeapYear(Date.tm_year) && Date.tm_mon > 2) {
		Sum += 1;
	}
	return Sum;
}