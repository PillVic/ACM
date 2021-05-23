#include<bits/stdc++.h>
using namespace std;
const int LEN=50001;
int tree[LEN];
int len;
int lowbit(const int& x){
    return x & (-x);
}
void update(int pos, const int& k){
    while(pos<=len){
        tree[pos] += k;
        pos += lowbit(pos);
    }
}
int query(int pos){
    int ans = 0;
    while(pos>0){
        ans += tree[pos];
        pos -=lowbit(pos);
    }
    return ans;
}
int query(const int& head, const int& tail){
    return query(tail)-query(head-1);
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int caseNum;
    cin>>caseNum;
    for(int caseid=1;caseid<=caseNum;caseid++){
        cin>>len;
        fill(tree, tree+len+1, 0);
        for(int i=1;i<=len;i++){
            int t;
            cin>>t;
            update(i, t);
        }
        cout<<"Case "<<caseid<<':'<<'\n';
        string s;
        while(cin>>s){
            if(s[0]=='E') break;
            int a, b;
            cin>>a>>b;
            if(s[0]=='Q'){
                cout<<query(a,b)<<'\n';
            }else{
                if(s[0] == 'S'){
                    b *=-1;
                }
                update(a, b);
            }
        }
    }
    return 0;
}
