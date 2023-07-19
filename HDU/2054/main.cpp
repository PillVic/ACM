#include<bits/stdc++.h>

using namespace std;

const char ENDLINE = '\n';

string realNumStr(const string& s){
    string sa = "";
    string sb = "";

    bool astart = false;
    bool bstart = false;
    for(const auto &c : s){
        if(c == '-'){
            sa += c;
            continue;
        } 
        if(c == '+') continue;
        if(not(astart) and c == '0'){
            continue;
        }
        if(c == '.'){
            bstart = true;
            continue;
        }
        astart = true;

        if((not bstart)){
            sa += c;
        }else{
            sb += c;
        }
    }
    if(sb == ""){
        return sa;
    }
    int t = sb.size()-1;
    while(sb[t] == '0' and t > 0 ) t--;
    if(t == 0 and sb[0] == '0'){
        return sa;
    }
    if(sa == "") sa = "0";
    return sa + "." + sb.substr(0, t+1);
}
int main(){
    ios::sync_with_stdio(false);
    string a, b;
    while(cin >> a >> b){
        if(realNumStr(a) == realNumStr(b)){
            cout << "YES" << ENDLINE;
        }else{
            cout << "NO" << ENDLINE;
        }
    }
}
