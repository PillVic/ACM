//Floyd算法可以算出地图中任意两个地点(x、y)的最短距离
//并且保存在maze[x][y]里
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define Max 0x3f3f3f3f //定义一个极大的数 表示走不通
int n;
int maze[101][101];

void Floyd()
{
    for(int k=1;k<=n;k++)//取一个中介
    {
        for(int i=1;i<=n;i++)//遍历起点
        {
            for(int j=1;j<=n;j++)//遍历终点
            {
                if(maze[i][k]<Max&&maze[k][j]<Max)//如果 从i到k 和 从k到j 能够走通，那么
                    maze[i][j]=min(maze[i][j],maze[i][k]+maze[k][j]);//更新最短距离
            }
        }
    }
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)&&n)
    {
        memset(maze,Max,sizeof(maze));//每次都要更新地图 转为完全走不通的状态
        while(m--)
        {
            int a,b,c;
            cin>>a>>b>>c;
            maze[a][b]=maze[b][a]=c;
        }
        Floyd();
        cout<<maze[1][n]<<endl;//题目要求1到n
    }
    return 0;
}
