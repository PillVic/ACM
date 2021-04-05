#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    string keyboard="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./ \n";
    map<char,int> mp;
    for(int i=0;i<keyboard.length();i++){
        mp[keyboard[i]]= i-1;
    }
    mp[' ']=keyboard.length()-2;
    mp['\n']=keyboard.length()-1;
    char t;
    while((t=getchar())!=EOF){
        cout<<keyboard[mp[t]];
    }
    return 0;
}
