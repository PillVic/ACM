#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    int len;
    while(cin>>len){
        if(len==0) break;
        vector<int> v(len);
        int tdx = -1;
        int m = 0x3fffffff;
        for(int i=0;i<v.size();i++){
            cin>>v[i];
            m = min(m, v[i]);
            if(m==v[i]) tdx = i;
        }
        swap(v[tdx], v[0]);
        cout<<v[0];
        for(int i=1;i<v.size();i++){
            cout<<" "<<v[i];
        }
        cout<<"\n";
    }
    return 0;
}
