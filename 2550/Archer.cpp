#include<bits/stdc++.h>

using namespace std;

typedef struct{
    int length;
    int num;
}arrow;

inline bool judge(arrow a, arrow b){
    return a.length< b.length;
}
void showArrow(arrow a){
    cout<<">+";
    for(int i=0;i<a.length-2;i++){
	cout<<"-";
    }
    cout<<"+>"<<endl;
}
void printArrow(vector<arrow> &v);
int main(){
    ios::sync_with_stdio(false);
    int casenum;
    cin>>casenum;
    while(casenum--){
	int lines;
	cin>>lines;
	vector<arrow> v;
	for(int i=0; i<lines;i++){
	    arrow a;
	    cin>>a.length>>a.num;
	    v.push_back(a);
	}
	printArrow(v);
    }
    return 0;
}
void printArrow(vector<arrow> &v){
    sort(v.begin(), v.end(), judge);
    for(const auto&t:v){
	for(int i=0;i<t.num;i++){
	    showArrow(t);
	}
	cout<<endl;
    }
}
