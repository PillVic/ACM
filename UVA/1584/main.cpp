#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("data.txt", "r", stdin);
#endif
    int caseNum;
    cin>>caseNum;
    while(caseNum--){
        string s;
        cin>>s;
        string ans=s;
        for(int i=0;i<s.length();i++){
            string temp = s.substr(i)+s.substr(0,i);
            if(temp<ans){
                ans = temp;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
