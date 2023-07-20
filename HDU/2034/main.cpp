#include<bits/stdc++.h>

using namespace std;
const char ENDLINE = '\n';

int main(void){
    ios::sync_with_stdio(false);
    int aLen, bLen;
    while(cin >> aLen >> bLen) {
        if(aLen == bLen and aLen == 0){
            break;
        }
        set<int> s1, s2;
        for(int i=0; i<aLen; i++){
            int t1;
            cin >> t1;
            s1.insert(t1);
        }
        for(int i=0; i<bLen; i++){
            int t2;
            cin >> t2;
            s2.insert(t2);
        }
        vector<int> v;
        for(const auto& e: s1){
            if(s2.find(e) == s2.end()){
                v.push_back(e);
            }
        }
        if(v.size() == 0){
            cout << "NULL" << ENDLINE;
        }else{
            for(int i=0; i<v.size(); i++){
                cout << v[i];
                if(i != v.size()-1){
                    cout << " ";
                }else{
                    cout << ENDLINE;
                }
            }
        }
    }
}
