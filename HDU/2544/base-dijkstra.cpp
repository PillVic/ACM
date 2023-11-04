#include<bits/stdc++.h>

using namespace std;
/**
 * 最短路径板子题
 * 此处采用dijkstra算法
 * */
const int MAX_NODE_NUM = 101;
const int inf = 0x1fffffff;

int G[MAX_NODE_NUM][MAX_NODE_NUM];

vector<int> dijkstra(const int& nodeNum, const int& start){
    vector<int> costs;
    for(int i=0;i<nodeNum;i++){
        costs.push_back(G[start][i]);
    }
    costs[start] = 0;
    vector<bool> visited(nodeNum, false);
    for(int j=0;j<nodeNum;j++){
        int minCost = inf;
        int idx = -1;
        //此处只采用最原始的方法遍历寻找
        //如果采用堆优化，可以将寻找最短开销的复杂度降到对数
        for(int i=0; i<nodeNum;i++){
            if((not visited[i]) and (costs[i] < minCost)){
                minCost = costs[i];
                idx = i;
            }
        }
        visited[idx] = true;
        for(int i=0; i< nodeNum;i++){
            costs[i] = min(costs[i], costs[idx] + G[idx][i]);
        }
    }
    return costs;
}
int main(void){
    ios::sync_with_stdio(false);
    int nodeNum, roadNum;
    while(cin>> nodeNum >> roadNum){
        if(nodeNum == 0 and roadNum == 0){
            break;
        }
        for(int i=0; i<nodeNum;i++){
            fill(G[i], G[i]+ nodeNum, inf);
        }
        for(int i=0;i<roadNum;i++){
            int x, y, cost;
            cin >> x >> y >> cost;
            x -= 1;
            y -= 1;
            G[x][y] = cost;
            //如果是有向图，去掉下面这句
            G[y][x] = cost;
        }
        cout << dijkstra(nodeNum, 0)[nodeNum-1] << '\n';
    }
    return 0;
}
