#include<bits/stdc++.h>

using namespace std;
/**
 * 典型的动态规划问题, 求n个不相交子序列的最大和
 * 设dp[i][j] 考虑前j个物品, 以j结尾, i个不相交子序列的最大和, 则有如下状态转移方程
 * dp[i][j] = max(dp[i][j-1]+ s[j], dp[i-1][k] + s[j]) 其中 k >= i-1, k< j
 * 设preMax[i][j] 为考虑前j个物品, 从0到j段序列的最大序列和, 则可将方程简化如下
 * dp[i][j] = max(dp[i-1][j-1] + s[j], preMax[i-1][j-1] + s[j])
 * */

const int LEN = 1000001;
const char ENDLINE = '\n';
const int INF = 0x7fffffff;

int s[LEN];
int dp[LEN];
int preMax[LEN];
int compute(const int& seqLen, const int& pairNum){
    //初始化
    fill(dp, dp + LEN, 0);
    fill(preMax, preMax + LEN, 0);
    int x = 0;
    for(int i=1; i<=pairNum; i++){
        x = -INF;
        for(int j=i-1; j<seqLen; j++){
            dp[j] = max(dp[j-1] + s[j], preMax[j-1] + s[j]) ;
            preMax[j-1] = x;
            x = max(x, dp[j]);
        }
    }
    return x;
}

int main(void) {
    ios::sync_with_stdio(false);
    int pairNum, seqLen;
    while(cin >> pairNum >> seqLen){
        for(int i=0; i < seqLen; i++){
            cin>> s[i];
        }
        cout << compute(seqLen, pairNum) << ENDLINE;
    }
    return 0;
}
