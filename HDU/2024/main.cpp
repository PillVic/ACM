#include<bits/stdc++.h>
#include <string>

using  namespace std;
const char ENDLINE = '\n';

int main(){
    ios::sync_with_stdio(false);
    int caseNum;
    cin >> caseNum;
    string s;
    getline(cin, s, '\n');
    while(caseNum--){
        string s;
        getline(cin, s, '\n');
        bool leagal = true;
        if(s[0] >= '0' and s[0] <= '9'){
            cout << "no" << ENDLINE;
            continue;
        }
        for(const auto& c:s){
            if((c >='0' and c <= '9') 
                    or (c >='a' and c <='z') or (c >= 'A' and c<='Z')
                    or (c == '_')){
            }else{
                leagal = false;
                break;
            }
        }
        if(leagal){
            cout << "yes" << ENDLINE;
        }else{
            cout << "no" << ENDLINE;
        }
    }
    return 0;
}
