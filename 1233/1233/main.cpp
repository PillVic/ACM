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

bool judge(road r1, road r2){
    return r1.cost < r2.cost;
}
int main(){
    ios::sync_with_stdio(false);
    int cityNum, roadNum;
    while(cin>>cityNum){
	if(cityNum == 0){
	    break;
	}
	int roadNum = (cityNum*(cityNum-1))/2;
	vector<road> r;
	for(int i=0;i<roadNum;i++){
	    road t;
	    cin>>t.x>>t.y>>t.cost;
	    t.x -=1;
	    t.y -=1;
	    r.push_back(t);
	}
	sort(r.begin(), r.end(), judge);
	Set S;
	Initialize(S, cityNum);
	int result = 0;
	for(const auto &t:r){
	    if(Find(t.x, S)!=Find(t.y, S)){
		result +=t.cost;
		SetUnion(S, t.x, t.y);
#ifdef LOCAL
		for(const auto i:S){
		    cout<<i<<" ";
		}
		cout<<endl;
		cout<<"BUIILD ROAD:"<<t.x<<" "<<t.y<<" "<<t.cost<<endl;
#endif
	    }
	}
	cout<<result<<endl;
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
