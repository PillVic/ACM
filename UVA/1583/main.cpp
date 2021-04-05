#include<bits/stdc++.h>
using namespace std;

int cal(int a){
    int bak=a;
    int r=0;
    while(a!=0){
        int t = a%10;
        a -=t;
        a/=10;
        r+=t;
    }
    return r+bak;
}
int arr[100001];
const int inf=0x7fffffff;
const int LEN=100001;
int main(void){
    ios::sync_with_stdio(false);
    fill(arr, arr+LEN, inf);
    for(int i=1;i<LEN;i++){
        arr[cal(i)] = min(i, arr[cal(i)]);
    }
    int caseNum;
    cin>>caseNum;
    while(caseNum--){
        int n;
        cin>>n;
        if(arr[n]==inf){
            cout<<0<<endl;
        }else{
            cout<<arr[n]<<endl;
        }
    }
    return 0;
}
