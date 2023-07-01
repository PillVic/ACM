#include<bits/stdc++.h>

using namespace std;
const int LEN = 102;
const char ENDLINE = '\n';
vector<int> seq;

vector<int> compute(const vector<int>& seq, const int& calLen, const int& avgNum){
    vector<int> res;
    int temp = 0;
    for(int i=1; i<= calLen; i++){
        temp += seq[i];
        if(i % avgNum == 0){
            res.push_back(temp/avgNum);
            temp = 0;
        }
    }
    if(temp != 0){
        res.push_back(temp / (calLen % avgNum));
    }
    return res;
}
void print(const vector<int> &v){
    for(int i=0; i < v.size(); i++){
        cout<<v[i];
        if(i < v.size() -1){
            cout<< " ";
        }
    }
    cout<<ENDLINE;
}
int main(void){
    ios::sync_with_stdio(false);
    vector<int> seq;
    for(int i=0;i<LEN;i++){
        seq.push_back(i * 2);
    }

    int calLen, avgNum;
    while(cin >> calLen >> avgNum){
        vector<int> res = compute(seq, calLen, avgNum);
        print(res);
    }
    return 0;
}
