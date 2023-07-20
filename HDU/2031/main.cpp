#include<bits/stdc++.h>

using namespace std;
const char ENDLINE = '\n';

int main(void) {
    ios::sync_with_stdio(false);
    int n, r;
    while(cin >> n >> r){
        if(n == 0){
            cout << "0" << ENDLINE;
            continue;
        }

        string dict="0123456789ABCDEFG";
        bool neg = n < 0;
        n = abs(n);
        string s;
        while(n != 0){
            s += dict[n%r];
            n /=r;
        }
        if(neg){
            s += "-";
        }
        reverse(s.begin(), s.end());
        cout << s << ENDLINE;
    }
    return 0;
}
