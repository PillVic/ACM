#include<bits/stdc++.h>

using namespace std;

typedef struct{
    int hour, min, second;
}date;
typedef struct{
    char ID[20];
    date come;
    date leave;
}record;

inline int caltime(date d){
    return d.hour*3600+d.min*60+d.second;
}

bool judge1(record &r1, record &r2){
    return caltime(r1.come) < caltime(r2.come);
}
bool judge2(record &r1, record &r2){
    return caltime(r1.leave) > caltime(r2.leave);
}
int main(){
    int daynum;
    cin>>daynum;
    while(daynum--){
	int lines;
	cin>>lines;
	vector<record> v;
	while(lines--){
	    record r;
	    scanf("%s %d:%d:%d %d:%d:%d", r.ID, 
		    &r.come.hour, &r.come.min, &r.come.second,
		    &r.leave.hour, &r.leave.min, &r.leave.second
		    );
	    v.push_back(r);
	}
	sort(v.begin(), v.end(), judge1);
	cout<<v[0].ID<<" ";
	sort(v.begin(), v.end(), judge2);
	cout<<v[0].ID<<endl;
#ifdef LOCAL
	cout<<"################################"<<endl;
	for(const auto&r:v){
	    printf("%s %d:%d:%d %d:%d:%d\n", r.ID, 
		    r.come.hour, r.come.min, r.come.second,
		    r.leave.hour, r.leave.min, r.leave.second
		    );
	}
#endif
    }
    return 0;
}
