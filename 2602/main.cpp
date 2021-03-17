#include<bits/stdc++.h>
using namespace std;
const int LEN=1001;
int dp[LEN];
int value[LEN];
int cost[LEN];
int main(void){
    ios::sync_with_stdio(false);
    int caseNum;
    cin>>caseNum;
    while(caseNum--){
        fill(dp,dp+LEN,0);
        int boneNum, capacity;
        cin>>boneNum>>capacity;
        for(int i=0;i<boneNum;i++){
            cin>>value[i];
        }
        for(int i=0;i<boneNum;i++){
            cin>>cost[i];
        }
        for(int i=0;i<boneNum;i++){
            for(int v=capacity;v>=0;v--){
                if(v-cost[i]<0) continue;
                dp[v] = max(dp[v-cost[i]]+value[i],dp[v]);
            }
        }
        cout<<dp[capacity]<<"\n";
    }
    return 0;
}
