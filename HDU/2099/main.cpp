#include <bits/stdc++.h>

using namespace std;

const int LEN = 100;

bool num[LEN] = {false};

vector<int> calNum(const int& a, const int& b) {
    vector<int> v;
    fill(num, num + 100, false);

    for (int i = 0; i < LEN; i++) {
        if (((a * 100 + i) % b) == 0) {
            num[i] = true;
        }
    }
    for (int i = 0; i < LEN; i++) {
        if (num[i]) {
            v.push_back(i);
        }
    }
    return v;
}
void printVec(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] < 10) {
            cout <<"0";
        }
        cout << v[i];
        if (i != v.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
    return;
}
int main() {
    ios::sync_with_stdio(false);
    int a, b;
    while (cin >> a >> b) {
        if (a == 0 and b == 0) {
            break;
        }
        printVec(calNum(a, b));
    }
    return 0;
}
