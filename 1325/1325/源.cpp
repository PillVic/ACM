/*
��������������Ϊ0�������ڵ����Ϊ1����ͨͼ
����Ϊ����������һϵ�нڵ�ָ����0,0��β
A->B ͨ���������Nodes[A]=B����ʾ Ĭ��Ԫ��ֵΪ0
ֻ����һ���ڵ�洢��ֵΪ0���������
����ڸ�ֵʱ�����Ǹ��ķ���Ԫ�ص�ֵ��˵����һ���ڵ㱻�ظ�ָ�򣬲�����
*/


#include<iostream>
#include<stack>

#define M 1000

using namespace std;

int Nodes[M];

bool IsATree(int a, int b) {
	if (a == b && a == 0) {
		return true;
	}
	//Initial 
	bool judge = true;
	memset(Nodes, 0, sizeof(Nodes));
	stack<int> r;
	r.push(a);
	int tempRoot = a;
	Nodes[b] = a;
	while (cin >> a >> b) {
		if (a == b && b == 0) {
			break;
		}
		//������һ�����㱻ָ������
		if (Nodes[b] != 0) {
			judge = false;
		}
		//һ�����ظ�ָ�򣬲��������ر����в���Ҫ����
		if (judge = false) {
			continue;
		}
		Nodes[b] = a;
		//�����������Ϊ0�Ľڵ�
		if (!r.empty()) {
			tempRoot = r.top();
			if (Nodes[tempRoot] != 0) {
				r.pop();
			}
		}
		if (Nodes[a] == 0) {
			r.push(a);
		}
	}
	//������û�����Ϊ0�Ľڵ�
	if (!judge || r.empty()) {
		return false;
	}
	tempRoot = r.top();
	r.pop();
	//���Ϊ0�Ľڵ�ֻ����һ��
	return r.empty() && Nodes[tempRoot] == 0;
}

int main() {
	int Case = 1;
	int a, b;
	while (cin >> a >> b) {
		if (a <0 && b <0) {
			break;
		}
		if (IsATree(a, b)) {
			cout << "Case " << Case << " is a tree." << endl;
		}
		else {
			cout << "Case " << Case << " is not a tree." << endl;
		}
		Case++;
	}
	return 0;
}