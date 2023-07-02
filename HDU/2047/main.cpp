#include<bits/stdc++.h>

using namespace std;

/**
 * 典型的动态规划问题, 三个元素的重复排列, 不允许连续出现OO
 * dp[i] 代表长度i的字符串排法
 * dp[i] = 2*dp[i-1] + 2 * dp[i-2]
 * */

const int LEN = 41;
const char ENDLINE = '\n';

long long dp[LEN];

void initDp(){
    dp[0] = 1;
    dp[1] = 3;
    for(int i=2; i < LEN; i++){
        dp[i] = 2 * (dp[i-1] + dp[i-2]);
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    initDp();
    int n;
    while(cin >> n){
        cout << dp[n] << ENDLINE;
    }
    return 0;
}
