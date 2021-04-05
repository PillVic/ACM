#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    int caseNum;
    cin>>caseNum;
    map<char,int>mp;
    mp['C']=12010;mp['H']=1008;mp['O']=16000;mp['N']=14010;
    char num[]="0123456789";
    for(int i=0;i<10;i++){
        mp[num[i]] = i;
    }
    while(caseNum--){
        string molecular;
        cin>>molecular;
        double mass = 0;
        int count=-1;
        int pre = 0;
        for(int i=0;i<molecular.length();i++){
            int kind = mp[molecular[i]];
            if(kind>=0 and kind <= 9){
                if(count==-1){
                    count =kind;
                    continue;
                }
                count = count*10+kind;
            }else {                
                if(count == -1){
                    mass +=pre;
                    count = -1;
                    pre = kind;
                    continue;
                }
                mass += count*pre;
                pre = kind;
                count = -1;
            }
        }
        if(count==-1){
            mass +=pre;
        }else{
            mass +=count*pre;
        }
        char str[100];
        sprintf(str,"%.3lf\n", mass/1000);
        cout<<str;
    }
    return 0;
}
