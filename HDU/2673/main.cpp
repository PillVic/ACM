#include<bits/stdc++.h>

using namespace std;
const char ENDLINE = '\n';
/*
 * 双针法板子题
 * */

int main(void){
    ios::sync_with_stdio(false);
    int seqLen;
    while( cin >> seqLen){
        vector<int> v(seqLen);
        for(int i=0; i<seqLen; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int p1 = v.size()-1, p2 = 0;
        for(int i=0; i<seqLen;i++){
            if(i%2 == 0){
                cout << v[p1--];
            }else{
                cout << v[p2++];
            }
            if(i != seqLen-1){
                cout << " ";
            }
        }
        cout << ENDLINE;
    }
    return 0;
}
