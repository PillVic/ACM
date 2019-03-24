#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int arr[4];
    bool first = true;
    while(true){
	cin>>arr[0]>>arr[1]>>arr[2]>>arr[3];
	if(arr[0]==arr[1]&&arr[1]==arr[2]&&
	   arr[2]==arr[3]&&arr[0]==0){
	    break;
	}
	if(!first){
	    cout<<endl;
	}
	first = false;
	vector<int> v;
	do{
	    int t = arr[0]*1000+arr[1]*100+arr[2]*10+arr[3];
	    if(t>=1000){
		v.push_back(t);
	    }
	}while(next_permutation(arr, arr+4));
	sort(v.begin(), v.end());
	int curt = v[0]/1000;
	for(int i=0;i<v.size();i++){
	    int a = v[i];
	    if(a/1000 !=curt){
		cout<<endl;
		curt = a/1000;
	    }else if(a!=v[0]){
		cout<<" ";
	    }
	    cout<<a;
	}
	cout<<endl;
    }
    return 0;
}
