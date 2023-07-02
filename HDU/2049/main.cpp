#include<bits/stdc++.h>

using namespace std;

/**
 * 对于长度为N的序列, M个元素错排的方案数
 * 可以这样理解步骤: 
 * 1. 选择M个元素 range(N, M)
 * 2. 对M个元素进行全错排
 * 问题就归约成计算全排列问题
 * 全排列有如下的公式 dp[i] = (dp[i-1] + dp[i-2]) * (i-1)
 * */

const char ENDLINE = '\n';
const int LEN = 21;

long long dp[LEN];
void initDp(){
    dp[0] = dp[1] = 0;
    dp[2] = 1;
    for(int i=3; i< LEN; i++){
        dp[i] = (i-1) * (dp[i-1] + dp[i-2]);
    }
}
long long calRangeNum(const int& a, const int& b){
    //计算排列
    long long tempA = 1;
    long long tempB = 1;
    for(int i=0;i<b;i++){
        tempA *=  a-i;
        tempB *= i+1;
    }
    return tempA / tempB;
}
int main(void) {
    ios::sync_with_stdio(false);
    initDp();

    int caseNum;
    cin >> caseNum;
    for(int i=0; i< caseNum; i++){
        int coupleNum, errorNum;
        cin >> coupleNum >> errorNum;
        cout << calRangeNum(coupleNum, errorNum) * dp[errorNum] << ENDLINE;
    }
    return 0;
}
