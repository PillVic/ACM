#include<bits/stdc++.h>

using namespace std;

const char ENDLINE = '\n';

int main(void) {
    ios::sync_with_stdio(false);
    int number;
    while(cin >> number){
        stack<int> stk;
        while(number != 0){
            stk.push(number %2);
            number = number / 2;
        }
        while(stk.size() != 0) {
            cout << stk.top();
            stk.pop();
        }
        cout << ENDLINE;
    }
    return 0;
}
