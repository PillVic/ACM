#include<bits/stdc++.h>

using namespace std;
/*
 * 非常简单的dp问题
 * dp[i] 代表站数为i时候的最初羊数量, 反过来理解, 就是当前羊-1乘2就是上一站的羊数量
 * 可得到状态转移方程如下
 * dp[i] = (dp[i-1] - 1) * 2
 * */

const char ENDLINE = '\n';
const int LEN = 31;

long long dp[LEN];
void initDp(){
    dp[0] = 3;
    for(int i = 1; i < LEN;i++){
        dp[i] = (dp[i-1] - 1) * 2;
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    initDp();
    int caseNum;
    cin >> caseNum;
    for(int i=0; i< caseNum; i++){
        int stationNum;
        cin >> stationNum;
        cout << dp[stationNum] << ENDLINE;
    }
    return 0;
}
