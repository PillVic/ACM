#include<bits/stdc++.h>

using namespace std;

#define LEN 100
#define MAX 0X3F3F3F3F

int main(){
    ios::sync_with_stdio(false);
    
    int roadNum, nearNum, destNum;
    while(cin>>roadNum>>nearNum>>destNum){
	static map <int, int> f;
	static int road[LEN][LEN];
	memset(road, MAX, sizeof(road));
	f.clear();
	int count = roadNum;
	while(count--){
	    int a, b, c;
	    cin>>a>>b>>c;
	    if(f.count(a)==0){
		f.insert(pair <int, int>(a, f.size()));
	    }
	    if(f.count(b)==0){
		f.insert(pair <int, int>(b, f.size()));
	    }
	    int i=f[a], j = f[b];
	    road[i][j] = min(road[i][j], c);
	    road[j][i] = road[i][j];
	}
	int begin = f.size();
	count = nearNum;
	while(count--){
	    int a;
	    cin>>a;
	    a = f[a];
	    road[begin][a] = road[a][begin] = 0;
	}
	count = destNum;
	static vector <int> v;
	while(count--){
	    int a;
	    v.push_back(f[a]);
	}
	bool Used[LEN];
	memset(Used, false, sizeof(Used));
	int cost[LEN];
	memset(cost, 1, sizeof(cost));
	for(int i=0;i<f.size();i++){
	    cost[i] = road[begin][i];
	}
	count = f.size();
	while(count--){
	    //Dijkstra
	    int tIndex = -1;
	    for(int i=0;i<f.size();i++){
		if(!Used[i]){
		    if(tIndex==-1||cost[i]<cost[tIndex]){
			tIndex = i;
		    }
		}
	    }
	    Used[tIndex] = true;
	    for(int i=0;i<f.size();i++){
		cost[i] = min(cost[i], cost[tIndex]+road[tIndex][i]);
	    }
	}
	int r = MAX;
	for(const auto &i:v){
	    r = min(r, cost[i]);
	}
	cout<<r<<endl;
    }
    return 0;
}
