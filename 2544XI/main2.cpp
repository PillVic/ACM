/*用Floyed 算法计算最短路径
 *
 */
#include<bits/stdc++.h>

using namespace std;

#define LEN 100
#define MAX 0x3f3f3f3f

int road[LEN][LEN];

int main(){
    ios::sync_with_stdio(false);

    int roadNum, turnNum;
    while(cin>>turnNum>>roadNum&&turnNum){
	memset(road, MAX, sizeof(road));
	for(int i=0;i<roadNum;i++){
	    static int a,b,c;
	    cin>>a>>b>>c;
	    road[a-1][b-1] = road[b-1][a-1] = c;
	}
	//Calculate
	for(int i=0;i<turnNum;i++){   //遍历起点
	    for(int j=0;j<turnNum;j++){ //遍历终点
		for(int k=0;k<turnNum;k++){ //遍历中间点
		    if(road[i][k]<MAX&&road[k][j]<MAX){
			road[i][j] = min(road[i][j], road[i][k]+road[k][j]);
		    }
		}
	    }
	}
	cout<<road[0][turnNum-1]<<endl;
    }
    return 0;
}
