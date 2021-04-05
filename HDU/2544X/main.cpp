/*
 * 采用迪杰斯特拉算法计算最短路径
 * 计算1到N的最短路径
 * */
#include<bits/stdc++.h>

using namespace std;


#define LEN 101
#define MAX 0x3f3f3f3f

int main(){
    ios::sync_with_stdio(false);

    int turnNum, roadNum;
    while(cin>>turnNum>>roadNum){
	if(turnNum==0&&roadNum==0){
	    break;
	}
	//Input road data
	static int road[LEN][LEN];
	for(int i=0;i<LEN;i++){
	    for(int t = 0;t<LEN;t++){
		road[i][t] = MAX;
	    }
	}
	for(int i=0;i<roadNum;i++){
	    int a,b,c;
	    cin>>a>>b>>c;
	    road[b-1][a-1] = road[a-1][b-1]=min(road[a-1][b-1], c);
	}
	//Dijkstra Algrithm Calculate
	static int dist[LEN];
	static bool Used[LEN];
	for(int i=0;i<LEN;i++){
	    dist[i] = MAX;
	    Used[i] = false;
	}
	dist[0] = 0;
	int count = turnNum;
	while(count--){
	    int tIndex = -1;
	    for(int t=0;t<turnNum;t++){
		if(!Used[t]){
		    if(tIndex==-1||dist[t]<dist[tIndex]){
			tIndex = t;
		    }
		}
	    }
	    Used[tIndex] = true;
	    for(int i=0;i<turnNum;i++){
		if(!Used[i]){
		    dist[i] = min(dist[i], dist[tIndex]+road[tIndex][i]);
		}
	    }
	}
	//Output the result
	cout<<dist[turnNum-1]<<endl;
    }
    return 0;
}
