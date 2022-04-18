#include<bits/stdc++.h>
#include <cstdint>
#include <iostream>

using namespace std;
const char endline = '\n';

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int caseNum;
    cin>>caseNum;
    while(caseNum--){
        double n;
        cin>>n;
        double t = n*log10(n);
        int a = pow(10, t-floor(t));
        cout<<a<<endline;
    }
    return 0;
}
