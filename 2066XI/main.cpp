/*
 * 本质还是求最短路径
 * 只是输入数据时不知道有几个城市
 * 所要求输出就是给定一系列起点S(m)和终点E(n)
 * 通过使用map来建立外部编号和内部编号的映射
 * 并通过map统计涉及的城市数量
 * 求出最小的通路
 * */
#include<bits/stdc++.h>

using namespace std;

#define LOCAL

#define MAX 0x3f3f3f3f
#define LEN 100

int main(){
    ios::sync_with_stdio(false);

    int roadNum, nearNum, destNum;
    while(cin>>roadNum>>nearNum>>destNum){
	static int road[LEN][LEN];
	memset(road, MAX, sizeof(road));
	//用于建立实际城市编号和内部编号的映射
	static map <int, int> f; 
	f.clear();
	//输入图
	int count = roadNum;
	while(count--){
	    int a,b,c;
	    cin>>a>>b>>c;
	    if(f.count(a)==0){
		f.insert(pair <int,int>(a, f.size()));
	    }
	    if(f.count(b)==0){
		f.insert(pair <int,int>(b, f.size()));
	    }
	    int i=f[a], j = f[b];
	    road[i][j] = min(road[i][j], c);
	    road[j][i] = road[i][j];
	}
	count = nearNum;
	static vector <int> nearv;
	nearv.clear();
	while(count--){
	    int a;
	    cin>>a;
	    nearv.push_back(f[a]);
	}
	count = destNum;
	static vector <int> destv;
	destv.clear();
	while(count--){
	    int a;
	    cin>>a;
	    destv.push_back(f[a]);
	}
	static int cost[LEN][LEN];
	memset(cost, MAX, sizeof(cost));
	for(const auto &p:nearv){
	    /*fixme*/ 
	    //用Dijsktra算法计算每一个起点的路径
	    //原地开销为0
	    cost[p][p] = 0;
	    static bool Used[LEN];
	    memset(Used, false, sizeof(Used));
	    count = f.size();
	    while(count--){
		int tIndex = -1;
		for(int i=0;i<f.size();i++){
		    if(!Used[i]){
			if(tIndex==-1||cost[p][i]<cost[p][tIndex]){
			    tIndex = i;
			}
		    }
		}
		Used[tIndex] = true;
		for(int i = 0;i<f.size();i++){
		    cost[p][i] = min(cost[p][i], cost[p][tIndex]+road[p][i]);
		}
	    }
	}
	int r = MAX;
	//直接遍历所有的目标路径，找出最短的
	for(const auto &i:nearv){
	    for(const auto &j:destv){
		r = min(r, cost[i][j]);
	    }
	}
	cout<<r<<endl;
    }
    return 0;
}
