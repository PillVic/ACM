//ACM1004
//���ַ�������Ƶ�ʽ���ͳ�ƣ�����������������������ָ�������ַ��������Ƶ����ߵ��ַ���
//���������������д�����һ��Ϊָ���ַ������ڶ���Ϊ��Ӧ�ַ�����Ƶ��,������Ƶ����ߵ��ַ���
//Ψһ���⣬��������ʾ��ɫ�ĵ���(charֻ������һ����ĸ),��ǰʵ�ֶ�һ���ַ���ͳ��
//�ݶ�����취������һ���ַ������飬��������Ȼ�������ַ���ת��ΪASCII��ת��int���ͣ��洢��colors��int�����飬��ȡʱת��ΪASCII���ȡ�ַ���
#include<iostream>
#include<string>
using namespace std;
int max(int a[], int number) {
	int n = 0;
	int t;
	t = 0;
	for (int i = 0; i<number; i++) {
		if (a[i]>n) {
			n = a[i];
			t = i;
		}
	}
	return t;
}
int main() {
	int times[10] = { 0 };
	int number;
	string colors[10] = { "" };
	while (cin >> number) {
		if (number == 0) {
			continue;
		}
		//���ȳ�ʼ������
		int * times = new int[number];
		string *colors = new string[number];
		for (int i = 0; i<number; i++) {
			times[i] = 0; colors[i] = "";
		}
		string color;
		//Ȼ���������ַ�����forѭ������ͳ��Ƶ��(ִ�д���ȡ����Number��С)
		for (int n = 0; n<number; n++) {
			cin >> color;
			int k;
			for (k = 0; k<number; k++) {
				if (colors[k] == color) {
					times[k] = times[k] + 1;
					break;
				}
			}if (k == number) {
				for (int m = 0; m<number; m++) {
					if (colors[m] == "") {
						colors[m] = color;
						times[m] = 1;
						break;
					}
				}
			}
		}
		cout << colors[max(times, number)] << endl;
		delete[]times;
		delete[]colors;
	}
	return 0;
}
