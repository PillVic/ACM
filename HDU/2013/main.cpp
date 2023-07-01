#include<bits/stdc++.h>


const int LEN = 40;
const char ENDLINE = '\n';
int main(void) {
    using namespace std;
    ios::sync_with_stdio(false);

    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    for(int i=1;i< LEN;i++){
        v.push_back((v[i] + 1) * 2);
    }
    int peachNum;
    while(cin>> peachNum){
        cout<<v[peachNum]<<ENDLINE;
    }
    return 0;
}
