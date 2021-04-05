/*
树：根结点是入度为0，其他节点入度为1的连通图
输入为不定数量的一系列节点指向，以0,0结尾
A->B 通过数组操作Nodes[A]=B来表示 默认元素值为0
只允许一个节点存储的值为0，即根结点
如果在赋值时发现是更改非零元素的值，说明有一个节点被重复指向，不是树
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
		//不允许一个顶点被指向两次
		if (Nodes[b] != 0) {
			judge = false;
		}
		//一旦被重复指向，不是树，回避所有不必要操作
		if (judge = false) {
			continue;
		}
		Nodes[b] = a;
		//更新所有入度为0的节点
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
	//树不能没有入度为0的节点
	if (!judge || r.empty()) {
		return false;
	}
	tempRoot = r.top();
	r.pop();
	//入度为0的节点只能有一个
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