#include<bits/stdc++.h>

using namespace std;

int calcouple(int a);
int main(){
    ios::sync_with_stdio(false);
    int lines;
    cin>>lines;
    while(lines--){
	int a;
	cin>>a;
	cout<<calcouple(a)<<endl;
    }
    return 0;
}
int calcouple(int a){
    int result = 1;
    for(int i=2;i<=sqrt(a);i++){
	if(a%i==0){
	    result +=i;
	    if(a/i!=i){
	        result +=a/i;
	    }
	}
    }
    return result;
}

