#include<bits/stdc++.h>

using namespace std;

bool judge(int a, int b){
    return a>b;
}
int main(){
    ios::sync_with_stdio(false);
    int length;
    while(cin>>length){
	vector<int> v;
	while(length--){
	    int a;
	    cin>>a;
	    v.push_back(a);
	}
	sort(v.begin(), v.end(), judge);
	length = v.size();
	if(length ==1){
	    cout<<v[0]<<endl;
	    break;
	}
	if(length%2==1){
	    length -=1;
	}
	for(int i=0;i< length/2;i++){
	    if(i!=0){
		cout<<" ";
	    }
	    cout<<v[i]<<" "<<v[v.size()-i-1];
	}
	if(v.size()!=length){
	    cout<<" "<<v[(v.size()-1)/2];
	}
	cout<<endl;
    }
    return 0;
}
