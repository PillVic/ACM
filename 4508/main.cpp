#include<bits/stdc++.h>
using namespace std;
const int LEN=100001;
const int len=101;
int dp[LEN];
int cost[len];
int value[len];
int main(void){
    ios::sync_with_stdio(false);
    int objNum;
    while(cin>>objNum){
        fill(dp,dp+LEN,0);
        for(int i=0;i<objNum;i++){
            cin>>value[i]>>cost[i];
        }
        int capacity;
        cin>>capacity;
        for(int i=0;i<objNum;i++){
            for(int v=cost[i];v<=capacity;v++){
                dp[v] = max(dp[v], dp[v-cost[i]]+value[i]);
            }
        }
        cout<<dp[capacity]<<"\n";
    }
    return 0;
}
