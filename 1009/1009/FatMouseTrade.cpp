#include<bits/stdc++.h>


using namespace std;

typedef struct{
    int cost;
    int value;
}food;

inline double calprice(food a){
    return a.cost*1.0/a.value;
}
bool judge(food a,food b){
    return calprice(a)<calprice(b);
}
double buyfood(int money, vector<food> &v);
int main(){
    int money, lines;
    while(cin>>money>>lines){
	if(money==lines&&lines==-1){
	    break;
	}
	vector<food> v;
	while(lines--){
	    food t;
	    cin>>t.value>>t.cost;
	    v.push_back(t);
	}
#ifdef LOCAL
	cout<<"##########################"<<endl;
	cout<<"Input DONE"<<endl;
	cout<<"Money: "<<money<<endl;
	cout<<"food  cost"<<endl;
	for(const auto&i:v){
	    cout<<i.value<<" "<<i.cost<<endl;
	}
#endif
	sort(v.begin(), v.end(), judge);
#ifdef LOCAL
	cout<<"SOURT DONE"<<endl;
	cout<<"food  cost"<<endl;
	for(const auto&i:v){
	    cout<<i.value<<" "<<i.cost<<endl;
	}
#endif
	printf("%.3lf\n", buyfood(money,v));
    }
    return 0;
}
double buyfood(int money, vector<food> &v){
    double result = 0;
    for(const auto &i:v){
	if(money>=i.cost){
	    /*afford it 
	     * Include buy all or free*/
	    money -= i.cost;
	    result +=i.value;
	}else{
	    /*cannot buy all*/
	    result += i.value*1.0/i.cost * money;
	    return result;
	}
    }
    return result;
}
