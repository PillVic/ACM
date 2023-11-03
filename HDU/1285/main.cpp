#include<bits/stdc++.h>

using namespace std;
/*
 * 拓扑排序板子题
 * */

void printVec(const vector<int>& v){
    for(int i=0; i< v.size(); i++){
        cout << v[i];
        if(i != v.size() -1){
            cout << " ";
        }else{
            cout << endl;
        }
    }
}
const int MAX_TEAM_NUM = 500;
vector<int> G[MAX_TEAM_NUM]={vector<int>(MAX_TEAM_NUM)};

vector<int> topoSort(const int& teamNum){
    vector<int> res;

    //计算各个定点的入度
    vector<int> pointed = vector<int> (teamNum, 0);
    set<int> points;
    for(int i=0; i< teamNum; i++){
        for(const auto& e: G[i]){
            pointed[e] += 1;
        }
        points.insert(i);
    }

    set<int> zeros;
    for(int i=0;i<pointed.size();i++){
        if(pointed[i] == 0){
            zeros.insert(i);
        }
    }
    while(not zeros.empty()){
        int zero = *zeros.begin();
        zeros.erase(zero);
        res.push_back(zero+1);
        for(const auto& e: G[zero]){
            pointed[e] -= 1;
            if(pointed[e] == 0){
                zeros.insert(e);
            }
        }
    }
    return res;
}
int main(void){
    ios::sync_with_stdio(false);
    int teamNum, gameNum;
    while(cin >> teamNum >> gameNum){
        for(int i=0; i<teamNum; i++){
            G[i].clear();
        }
        for(int i=0; i<gameNum; i++){
            int x, y;
            cin >> x >> y;
            x -= 1;
            y -= 1;
            G[x].push_back(y);
        }
        printVec(topoSort(teamNum));
    }
}
