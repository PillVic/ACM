#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b);
int main(){
    ios::sync_with_stdio(false);
    int lines;
    cin>>lines;
    while(lines--){
	int a, c;
	cin>>a>>c;
	int b = 2;
	while(gcd(a,b)!=c||b==c){
	    b++;
	}
	cout<<b<<endl;
    }
    return 0;
}
int gcd(int a, int b){
    while(a%b!=0){
	int c = b;
	b = a%b;
	a = c;
    }
    return b;
}
