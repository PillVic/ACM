#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int lines;
    while(cin>>lines){
	vector<int> v;
	while(lines--){
	    int a;
	    cin>>a;
	    v.push_back(a);
	}
	sort(v.begin(), v.end());
	int length = v.size();
	if(length%2==0){
	    cout<<v[length/2-1]<<endl;
	}else{
	    cout<<v[(length-1)/2]<<endl;
	}
    }
    return 0;
}
