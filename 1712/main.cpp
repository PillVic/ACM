#include<bits/stdc++.h>
using namespace std;
const int LEN=101;
int dp[LEN];
int value[LEN];
int main(void){
    ios::sync_with_stdio(false);
     cin.tie(0);cout.tie(0);
     int courseNum, dayNum;
     while(cin>>courseNum>>dayNum){
         if(courseNum==dayNum and dayNum == 0) break;
         fill(value, value+LEN, 0);
         fill(dp,dp+LEN,0);
         for(int i=0;i<courseNum;i++){
             for(int i=1;i<=dayNum;i++){
                 cin>>value[i];
             }
             /*本题为标准的分组背包问题
              * 每组最多选一个物品,组最多选一次,
              * 组内遍历,组件是01背包问题,因而采用倒序遍历
              * dp[i][v]=max(dp[i-1][v-k]+value[i-1][k]) (k\in [0,min(v,dayNum)])
              */
             for(int v=dayNum;v>=0;v--){
                 int r = dp[v];
                 for(int k=1;k<=dayNum;k++){
                     if(v-k<0) break;
                     r = max(r,dp[v-k]+value[k]);
                 }
                 dp[v] = r;
             }
         }
         cout<<dp[dayNum]<<"\n";
     }
    return 0;
}
