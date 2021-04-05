#include<bits/stdc++.h>
using namespace std;
int main(void){
#ifdef LOCAL 
    freopen("data.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    int arr[10];
    int n;
    cin>>n;
    while(n--){
        fill(arr,arr+10,0);
        int t;
        cin>>t;
        for(int i=1;i<=t;i++){
            int temp = i;
            while(temp!=0){
                int rest = temp%10;
                arr[rest]++;
                temp/=10;
            }
        }
        cout<<arr[0];
        for(int i=1;i<10;i++){
            cout<<" "<<arr[i];
        }
        cout<<endl;
    }
    return 0;
}
