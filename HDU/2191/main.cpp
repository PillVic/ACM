#include<bits/stdc++.h>
using namespace std;
const int LEN=101;
int dp[LEN];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int caseNum;
    cin>>caseNum;
    while(caseNum--){
        fill(dp,dp+LEN,0);
        int capacity, objNum;
        cin>>capacity>>objNum;
        for(int i=0;i<objNum;i++){
            int cost,value,num;
            cin>>cost>>value>>num;
            for(int v=capacity;v>=0;v--){
                for(int t=1;t<=num and v-t*cost>=0;t++){
                    dp[v] = max(dp[v],dp[v-t*cost]+t*value);
                }
            }
        }
        cout<<dp[capacity]<<endl;
    }
    return 0;
}
