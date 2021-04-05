#include<bits/stdc++.h>

using namespace std;
//DisJoint SET 
typedef vector<int> Set;
typedef int SetType;
typedef int ElementType;

void Initialize(Set &S, int length);
void SetUnion(Set &S, SetType Root1, SetType Root2);
SetType Find(ElementType x, Set &S);
/////////////////////////

typedef struct{
    int x, y;
    int cost;
}road;


int main(){
    ios::sync_with_stdio(false);
    int cityNum, roadNum;
    while(cin>>cityNum>>roadNum){
    vector<road> r;
    for(int i=0;i<roadNum;i++){
        road t;
        cin>>t.x>>t.y;
        t.x -=1;
        t.y -=1;
        r.push_back(t);
    }
    Set S;
    Initialize(S, cityNum);
    for(const auto &t:r){
        if(Find(t.x, S)!=Find(t.y, S)){
        SetUnion(S, t.x, t.y);
        }
    }
    sort(S.begin(), S.end());
    int t = 0;
    int j=S[0];
    for(const auto i:S){
        if(j!=i){
        j = i;
        t+=1;
        }
    }
    cout<<t<<endl;
    }
    return 0;
}
void Initialize(Set &S, int length){
    for(int i=0;i<length;i++){
    S.push_back(i);
    }
}
void SetUnion(Set &S, SetType Root1, SetType Root2){
    int i = min(S[Root1], S[Root2]);
    int j = S[Root1]+S[Root2] - i;
    for(auto &k:S){
    if(k == j){
        k = i;
    }
    }
}
SetType Find(ElementType x, Set &S){
    return S[x];
}
