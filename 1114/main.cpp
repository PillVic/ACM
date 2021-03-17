#include<bits/stdc++.h>
using namespace std;
const int LEN=100001;
const int inf=0x3fffffff;
int dp[LEN];
int value[LEN];
int cost[LEN];
int main(void){
    ios::sync_with_stdio(false);
    int caseNum;
    cin>>caseNum;
    while(caseNum--){
        int empty,full;
        cin>>empty>>full;
        int capacity = full-empty;
        fill(dp,dp+LEN,inf);
        dp[0] = 0;
        int coinNum;
        cin>>coinNum;
        for(int i=0;i<coinNum;i++){
            cin>>value[i]>>cost[i];
        }
        for(int i=0;i<coinNum;i++){
            for(int v=0;v<=capacity;v++){
                if(v-cost[i]<0) continue;
                dp[v]=min(dp[v], dp[v-cost[i]]+value[i]);
            }
        }
        char ans[1000];
        if(dp[capacity]!=inf){
            sprintf(ans, "The minimum amount of money in the piggy-bank is %d.\n", dp[capacity]);
        }else{
            sprintf(ans, "This is impossible.\n");
        }
        cout<<ans;
    }
    return 0;
}
