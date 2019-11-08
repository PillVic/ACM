#include<iomanip>
#include<bits/stdc++.h>

using namespace std;

#define p 10000

int main(){
    ios::sync_with_stdio(false);
    static int num[40000];
    int n;
    while(cin>>n){
	if(n==0){
	    cout<<1<<endl;
	    continue;
	}
	memset(num, 0, sizeof(num));
	num[0]=1;
	int top = 0;
	n++;
	while(n--){
	    int a=0;
	    if(n==0){
		break;
	    }
	    for(int i=0;i<=top;i++){
		int t = num[i]*n;
		num[i] = (t+a)%p;
		a = (t+a)/p;
	    }
	    if(a!=0){
		num[top+1] = a;
		top++;
	    }
	}
	if(num[top]){
	    cout<<num[top];
	}
	for(int i=top-1;i>=0;i--){
	    cout.fill('0');
	    cout.width(4);
	    cout<<num[i];
	}
	cout<<endl;
    }
    return 0;
}
