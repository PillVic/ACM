#include<bits/stdc++.h>
using namespace std;

int main(void){
#ifdef LOCAL 
    freopen("data.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int caseNum;
    cin>>caseNum;
    while(caseNum--){
        string str;
        cin>>str;
        int r = str.length();
        for(int t=1;t<str.length();t++){
            if(str.length()%t!=0) continue;
            bool found = true;
            string sample = str.substr(0,t);
            for(int jump=0;jump+t<=str.length();jump+=t){
                string sub = str.substr(jump, t);
                if(sub != sample){
                    found = false;
                    break;
                }
            }
            if(found){
                r = t;
                break;
            }
        }
        if(caseNum!=0){
            cout<<r<<endl<<endl;
        }else{
            cout<<r<<endl;
        }
    }
    return 0;
}
