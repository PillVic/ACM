#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int caseNum;
    while(cin>>caseNum){
        double r = 0;
        int m=0x3fffffff;
        int M=-1;
        for(int i=0;i<caseNum;i++){
            int t;
            cin>>t;
            m = min(m, t);
            M=max(M, t);
            r+=t;
        }
        char str[100];
        sprintf(str, "%.2lf\n", (r-m-M)/(caseNum-2));
        cout<<str;
    }
    return 0;
}
