#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const double eps = 1e-6;

 struct Point{
    double x, y;
    Point (double x=0, double y=0):x(x), y(y){}
    Point operator +(const Point &b)const{
	return Point(x+b.x, y+b.y);
    }
    Point operator -(const Point &b)const{
	return Point(x-b.x, y-b.y);
    }
    //向量的点乘
    double operator *(const Point &b)const{
	return x*b.x+y*b.y;
    }
    //向量的叉乘
    double operator ^(const Point &b)const{
	return x*b.y - b.x*y;
    }
};

static Point polygons [105];

int dcmp(double x){
    //三态函数，判断eps精度下的大小关系
    if(fabs(x)<eps){
	return 0;
    }else{
	return x<0?-1:1;
    }
}

bool isInLine(Point p1, Point p2, Point Q){
    //判断Q是否在P1P2的线段上
    return dcmp((p1-Q)^(p2-Q))==0&&dcmp((p1-Q)*(p2-Q))<=0;
}

bool isInPolygon(Point p, int pointCount){
    //判断点p在多边形内-射线法
    bool flag = false;
    for( int i = 1, j = pointCount;i<=pointCount;j=i++){
	//一条边的两个顶点
	Point p1 = polygons[i];
	Point p2 = polygons[j];

	//点在多边形一条边上
	if(isInLine(p1, p2, p)){
	    return true;
	}
	//在多边形里面
	//以P点做一条水平向右的射线

	//1. 线段在点的上下，而不是一边
	bool isUpDownLine = (dcmp(p1.y-p.y)>0 !=dcmp(p2.y-p.y)>0);
	if(isUpDownLine){
	    //2、点在射线与线段交点的左边
	    //直线应该是y=kx+b
	    //加入当前点是x1, y1 那么y>kx+b说明点在直线左边， 反之在右边
	    /*
	     * p.x <(p.y-p1.y)/k+p1.x
	     * k*p.x <p.y-p1.y+k*p1.x
	     * p.y-p1.y+k*(p1.x-p.x)>0
	     * p.y-p1.y>k*(p.x-p1.x)
	     * 对于如果向量P1P的斜率大雨P1P2的斜率，则P在P1P2的左边
	     * */
	    bool isLeft = dcmp(p.x- (p.y-p1.y)*(p1.x-p2.x)/(p1.y-p2.y)-p1.x)<0;

	    if(isLeft){
		flag =!flag;
	    }
	}
    }

    return flag;
}

int main(){
    int caseCount, pointCount;
    while(scanf("%d", &pointCount)){
	for(int i=1; i<=pointCount;i++){
	    scanf("%lf %lf", &polygons[i].x, &polygons[i].y);
	}

	Point point;
	scanf("%d", &caseCount);

	while(caseCount--){
	    scanf("%lf %lf", &point.x, &point.y);

	    if(isInPolygon(point, pointCount)){
		printf("Yes\n");
	    }else{
		printf("No\n");
	    }
	}
    }
    return 0;
}
