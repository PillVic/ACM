#include<bits/stdc++.h>
#include<bits/extc++.h>

using namespace std;
/*
 * 最小生成树算法板子题
 * 可以用prim, kruskal算法来做，都可以
 * kruskal 边优先
 * */
const int MAX_TOWN_NUM = 1001;
const int MAX_ROAD_NUM = MAX_TOWN_NUM * MAX_TOWN_NUM;
const int inf = 0x7fffffff;

//下面实现并查集
//如果>=0 则表示父节点，如果 <0,则表示为整个集合的节点数量
vector<int> initSet(const int& n){
    vector<int> v;
    for(int i=0; i<n;i++){
        v.push_back(-1);
    }
    return v;
}
int findRoot(const vector<int>& v, int id){
    while(v[id] >= 0 ){
        id = v[id];
    }
    return id;
}
void merge(vector<int>& v, const int& b, const int& a){
    int rootA = findRoot(v, a);
    int rootB = findRoot(v, b);
    if(rootA == rootB){
        return;
    }
    if(rootA < rootB){
        swap(rootA, rootB);
    }
    v[rootA] += v[rootB];
    v[rootB] = rootA;
}
bool IsUnion(const vector<int>& v, const int& x, const int& y){
    return findRoot(v,x) == findRoot(v, y);
}

typedef struct{
    int x;
    int y;
    int cost;
}road;

int main(){
    ios::sync_with_stdio(false);
    int townNum, roadNum;
    vector<road> roads;
    while (cin >> townNum){
        if(townNum == 0){
            break;
        }
        int roadNum = (townNum * (townNum - 1)) /2;
        roads.clear();
        for(int i=0;i<roadNum;i++){
            road r;
            cin >> r.x >> r.y >> r.cost;
            r.x -= 1;
            r.y -= 1;
            roads.push_back(r);
        }
        sort(roads.begin(), roads.end(), [](const road& a,const road& b){
                return a.cost > b.cost;
        });
        //kruskal算法：在不造成环的情况下，尽可能找最小边
        vector<int> towns = initSet(townNum);
        int totalCost = 0;
        for(int i=0; i<townNum;i++){
            while(not roads.empty()){
                road r = roads[roads.size()-1];
                roads.pop_back();
                if(not IsUnion(towns, r.x, r.y)){
                    merge(towns, r.x, r.y);
                    totalCost += r.cost;
                    break;
                }
            }
        }
        cout << totalCost << '\n';
    }
    return 0;
}
