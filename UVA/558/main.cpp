/*判断图是否有负环
 * 采用bellman-ford算法
 * 只要在进行n-1次迭代后,依然能缩小,则证明存在环
 * */
#include<bits/stdc++.h>
using namespace std;
const int LEN=1001;
const int inf=0x3fffffff;
int g[LEN][LEN];
typedef struct{
    int u,v;
    int cost;
}edge;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int caseNum;
    cin>>caseNum;
    while(caseNum--){
        int nodeNum, edgeNum;
        cin>>nodeNum>>edgeNum;
        fill(g[0], g[0]+nodeNum*nodeNum, inf);
        for(int i=0;i<nodeNum;i++) g[i][i] = 0;
        vector<edge> e(edgeNum);
        for(auto &i:e) cin>>i.u>>i.v>>i.cost;
        for(int k=1;k<=e.size();k++){
            for(const auto &t:e){
                g[0][t.v] = min(g[0][t.v], g[0][t.u]+t.cost);
            }
        }
        char str[100] = "not possible\n";
        bool check = false;
        for(const auto &t:e){
            if(g[0][t.v]> g[0][t.u]+t.cost){
                check = true;
                break;
            }
        }
        if(check) sprintf(str, "possible\n");
        cout<<str;
    }
    return 0;
}
