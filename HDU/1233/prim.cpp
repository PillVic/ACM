#include<bits/stdc++.h>

using namespace std;
/*
 * 最小生成树板子题
 * 此处使用Prim算法实现
 * */

const int MAX_TOWN = 101;
const int inf = 0x3fffffff;
int G[MAX_TOWN][MAX_TOWN];

int prime(const int& townNum){
    int totalCost = 0;
    vector<int> costs = vector<int> (townNum, inf);
    vector<bool> visited = vector<bool> (townNum, false);
    //任意一个点作为起点都可以, 直接约定0为起点
    costs[0] = 0;
    for(int i=0;i<townNum; i++){
        int minCost = inf;
        int town = -1;
        for(int j=0; j< townNum;j++){
            if(minCost > costs[j] and (not visited[j])){
                minCost = costs[j];
                town = j;
            }
        }
        visited[town] = true;
        totalCost += minCost;
        for(int targetTown = 0; targetTown<townNum;targetTown++){
            if(not visited[targetTown]){
                costs[targetTown] = min(costs[targetTown], G[town][targetTown]);
            }
        }
    }
    return totalCost;
}
int main(void){
    ios::sync_with_stdio(false);
    int townNum;
    while(cin >>  townNum){
        if(townNum == 0){
            break;
        }
        int roadNum = (townNum * (townNum - 1))/2;
        for(int i=0; i<roadNum; i++){
            int x, y, cost;
            cin >> x >> y >> cost;
            x -= 1;
            y -= 1;
            G[x][y] = G[y][x] = cost;
        }
        cout << prime(townNum) << endl;
    }
    return 0;
}
