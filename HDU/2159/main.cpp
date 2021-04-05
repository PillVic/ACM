#include<bits/stdc++.h>
using namespace std;
const int LEN=101;
int dp[LEN][LEN];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int need, persist, objNum, killLimit;
    while(cin>>need>>persist>>objNum>>killLimit){
        for(int i=0;i<LEN;i++){
            for(int j=0;j<LEN;j++){
                dp[i][j] = 0;
            }
        }
        for(int i=0;i<objNum;i++){
            int cost, value;
            cin>>value>>cost;
            /*dp[i][v][p] 在考虑前i个物品情况下,容量为v的背包最多拿p个物品的最大价值
             * dp[i][v][p]=max(dp[i-1][v][p],dp[i-1][v-k*cost[i]][p-k]+k*value[i])
             * 可以优化为dp[v][p]=max(dp[v][p],dp[v-cost[i][p-1]+value[i])
             * */
            for(int v=cost;v<=persist;v++){
                for(int p=1;p<=killLimit;p++){
                    dp[v][p] = max(dp[v][p], dp[v-cost][p-1]+value);
                }
            }
        }
        int r = 0;
        while(dp[r][killLimit]<need){
            r++;
            if(r>persist) break;
        }
        if(r>persist) {
            cout<<-1<<"\n";
        }else{
            cout<<persist-r<<"\n";
        }
    }
    return 0;
}
