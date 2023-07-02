#include<bits/stdc++.h>

using namespace std;

const int LEN = 10001;
const char ENDLINE = '\n';
int main(void) {
    ios::sync_with_stdio(false);
    vector<int> v(LEN);
    fill(v.begin(), v.end(), 1);
    v[0] = v[1] = 0;
    for(int i=2;i<LEN;i++){
        for(int j=2; j*i <LEN;j++){
            v[i * j] = 0;
        }
    }
    set<int> primes;
    for(int i=0;i<LEN;i++){
        if(v[i] == 1){
            primes.insert(i);
        }
    }
    int n;
    while(cin >> n){
        if(n == 0 ){
            break;
        }
        int matchCount = 0;
        for(const auto &i : primes){
            if(2 * i >= n){
                break;
            }
            if(primes.find(n-i) != primes.end()){
                matchCount++;
            }
        }
        cout << matchCount << ENDLINE;
    }
    return 0;
}
