#include<bits/stdc++.h>

using namespace std;
/*
 * 并查集板子题
 * */
const int MAX_TOWN_NUM = 1001;
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


int main(){
    ios::sync_with_stdio(false);
    int townNum, roadNum;
    while (cin >> townNum){
        if(townNum == 0){
            break;
        }
        cin >> roadNum;
        vector<int> towns = initSet(townNum);
        for(int i=0; i< roadNum; i++){
            int x, y;
            cin >> x >> y;
            x -= 1;
            y -= 1;
            merge(towns, x, y);
        }
        int idealRoot = -1 * townNum;
        int rootNum = 0;
        for(const auto &i:towns){
            if(i < 0 ){
                rootNum += 1;
            }
        }
        cout << rootNum - 1<< endl;
    }
    return 0;
}
