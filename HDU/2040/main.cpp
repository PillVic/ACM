#include<bits/stdc++.h>

using namespace std;

const char ENDLINE = '\n';

int sumMod(const int& a){
    int r = 0;
    for(int i=1; i < a; i++){
        if(a % i == 0){
            r += i;
        }
    }
    return r;
}
int main(void) {
    ios::sync_with_stdio(false);
    int caseNum;
    cin>>caseNum;
    for(int i = 0; i< caseNum; i++){
        int a, b;
        cin >> a >> b;
        int sumA = sumMod(a);
        int sumB = sumMod(b);
        if(sumA == b && sumB == a){
            cout << "YES" << ENDLINE;
        } else {
            cout << "NO" << ENDLINE;
        }
    }
    return 0;
}
