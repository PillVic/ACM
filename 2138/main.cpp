#include<bits/stdc++.h>

using namespace std;

int getrand(int a, int b){
    return rand()%(b-a+1)+a;
}
bool IsPrime(int a);
int main(){
    ios::sync_with_stdio(false);
    int lines;
    while(cin>>lines){
	int num = 0;
	while(lines--){
	    int a;
	    cin>>a;
	    if(IsPrime(a)){
		num +=1;
	    }
	}
	cout<<num<<endl;
    }
    return 0;
}
bool IsPrime(int a){
    /*miller rabin prime test*/
    if(a%2==0){
	return a==2;
    }
    for(int i=2;i<=sqrt(a);i++){
	if(a%i==0){
	    return false;
	}
    }
#ifdef LOCAL
    cout<<"IS PRIME: "<<a<<endl;
#endif 
    return true;
}
