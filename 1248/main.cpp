#include<bits/stdc++.h>
using namespace std;
const int LEN=10001;
const int inf=0x3fffffff;
int dp[LEN];
int main(void){
    ios::sync_with_stdio(false);
//    cin.tie(0); cout.tie(0);
    int caseNum;
    cin>>caseNum;
    int cost[3]={150, 200, 350};
    while(caseNum--){
        int capacity;
        cin>>capacity;
        fill(dp, dp+LEN,inf);
        dp[0]=0;
        for(int i=0;i<3;i++){
            for(int v=0;v<=capacity;v++){
                if(v-cost[i]<0) continue;
                dp[v] = min(dp[v], dp[v-cost[i]]+cost[i]);
            }
        }
        int r=capacity;
        while(dp[r]>10000) r--;
        cout<<capacity-r<<"\n";
    }
    return 0;
}
