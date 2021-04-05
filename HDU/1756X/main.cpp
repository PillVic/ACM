#include<bits/stdc++.h>

using namespace std;

typedef struct{
    int x;
    int y;
}point;

void CheckArrow(point p, vector <point> &v);
int main(){
    ios::sync_with_stdio(false);
    int length;
    while(cin>>length){
	static vector <point> v;
	v.clear();
	while(length--){
	    point p;
	    cin>>p.x>>p.y;
	    v.push_back(p);
	}
	cin>>length;
	while(length--){
	    point p;
	    cin>>p.x>>p.y;
	    CheckArrow(p, v);
	}

    }
    return 0;
}
void CheckArrow(point p, vector <point> &v){

}
