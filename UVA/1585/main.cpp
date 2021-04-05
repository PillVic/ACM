#include<bits/stdc++.h>
using namespace std;
int main(void){
#ifdef LOCAL
    freopen("data.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    string str;
    int caseNum;
    cin>>caseNum;
    while(caseNum--){
        cin>>str;
        int score = 0;
        int ocount=0;
        for(const auto&i:str){
            if(i=='O'){
                score += ++ocount;
            }else{
                ocount = 0;
            }
        }
        cout<<score<<endl;
    }
    return 0;
}
