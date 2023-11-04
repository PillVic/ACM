#include<bits/stdc++.h>

using namespace std;
/*
 * 无向最短路径板子题
 * 此次采用floyd算法
 * */

const int MAX_NODE_NUM = 101;
const int inf = 0x1f3f3f3f;

int G[MAX_NODE_NUM][MAX_NODE_NUM];
int main(void){
    ios::sync_with_stdio(false);
    int nodeNum, roadNum;
    while(cin>> nodeNum >> roadNum){
        if(roadNum == 0 and nodeNum == 0){
            break;
        }
        for(int i=0;i<nodeNum;i++){
            fill(G[i], G[i]+nodeNum, inf);
        }
        for(int i=0;i<roadNum;i++){
            int x, y, cost;
            cin >> x >> y >> cost;
            x -= 1;
            y -= 1;
            G[x][y] = cost;
            //如果有向，就把下面这句去掉
            G[y][x] = cost;
        }
        for(int k=0;k<nodeNum;k++){
            for(int i=0;i<nodeNum;i++){
                for(int j=0;j<nodeNum;j++){
                    G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
                }
            }
        }
        cout << G[0][nodeNum-1] << '\n';
    }
    return 0;
}
