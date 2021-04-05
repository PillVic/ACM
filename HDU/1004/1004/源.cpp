//ACM1004
//对字符串出现频率进行统计，首先输入样本容量，输入指定数量字符串后输出频率最高的字符串
//本题可以用数组进行处理，第一行为指定字符串，第二行为对应字符串的频率,最后输出频率最高的字符串
//唯一问题，如何输入表示颜色的单词(char只能输入一个字母),当前实现对一个字符的统计
//暂定解决办法：定义一个字符串数组，接收输入然后将输入字符串转化为ASCII码转成int类型，存储到colors的int型数组，读取时转换为ASCII码读取字符串
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
		//首先初始化数组
		int * times = new int[number];
		string *colors = new string[number];
		for (int i = 0; i<number; i++) {
			times[i] = 0; colors[i] = "";
		}
		string color;
		//然后对输入的字符串用for循环进行统计频率(执行次数取决于Number大小)
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
