#include<bits/stdc++.h>

/**
 * 求n个不同小球的全错排的概率
 * 是典型的古典概型问题
 * 可以用递推法计算n的错排数
 * dp[i] = (i-1) * (dp[i-1] + dp[i-2] )
 * */
using namespace std;

const char ENDLINE = '\n';
const int LEN = 22;

long long dp[LEN];
void initDp(){
    dp[0] = dp[1] = 0;
    dp[2] = 1;
    for(int i = 3; i< LEN; i++){
        dp[i] = (i-1) * (dp[i-1] + dp[i-2]);
    }
}
long long factorial(const int& n){
    if(n <= 1){
        return 1;
    }
    return factorial(n-1) * n;
}
int main() {
    ios::sync_with_stdio(false);
    initDp();
    int caseNum;
    cin >> caseNum;
    for(int i = 0; i < caseNum; i++){
        int n;
        cin >> n;

        double rate = (dp[n] *1.0)/factorial(n);
        cout << setprecision(2) << std::fixed << rate * 100 << "%" << ENDLINE;
    }
	return 0;
}
