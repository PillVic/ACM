#include<bits/stdc++.h>

using namespace std;

/**
 * 典型的动态规划问题
 * 状态的关键在于教师的工资值
 * dp[i] = min (dp[k]+ dp[i-k])
 * 人民币一共有100元、50元、10元、5元、2元和1元六种, 意味着这些dp对应的值为1
 * 同时可注意到, 在>100时, 可以把工资拆分成两部分, 可以用100支付的, 和零钱
 * 即拆分为kv+b
 * */

const int INF = 0x7fffffff;
const int LEN = 102;
const char ENDLINE = '\n';
vector<int>  buildDp(){
    vector<int> dp(LEN);
    fill(dp.begin(), dp.end(), INF);

    dp[0] = 0;
    dp[100] = dp[50] = dp[10] = dp[5] = dp[2] = dp[1] = 1;
    for(int i=3; i< LEN; i++){
        for(int k = 1; k < i ; k++){
            if(i-k <=0){
                break;
            }
            dp[i] = min(dp[i], dp[k]+ dp[i-k]);
        }
    }
    return dp;
}

int calWage(const vector<int> &dp, const int& wage){
    if(wage <= 100){
        return dp[wage];
    }
    int minorMoney = wage % 100;
    int mainMoney = wage - minorMoney;
    return dp[minorMoney] + (mainMoney /100);
}
int main(void) {
    ios::sync_with_stdio(false);

    vector<int> dp = buildDp();

    int teacherNum;
    while(cin>>teacherNum){
        if(teacherNum == 0){
            break;
        }
        int res = 0;
        for(int i=0; i< teacherNum; i++){
            int wage;
            cin >> wage;
            res += calWage(dp, wage);
        }
        cout<< res << ENDLINE;
    }
    return 0;
}
