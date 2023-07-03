#include<bits/stdc++.h>

using namespace std;

const char ENDLINE = '\n';

char getMaxChar(const string& s){
    char t = 'a';
    for(const auto &c : s){
        if(t < c){
            t = c;
        }
    }
    return t;
}
int main(void) {
    ios::sync_with_stdio(false);
    string s;
    while(cin >> s) {
        char maxChar = getMaxChar(s);
        for(const auto &c : s){
            cout << c;
            if(c == maxChar){
                cout << "(max)";
            }
        }
        cout << ENDLINE;
    }
    return 0;
}
