#include<bits/stdc++.h>
#include <ostream>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    int length;
    int caseNum = 1;
    while(cin>>length){
        if(length == 0){
            break;
        }
        vector<int> ans, guess;
        for(int i=0;i<length;i++){
            int t;
            cin>>t;
            ans.push_back(t);
        }
        cout<<"Game "<<caseNum++<<":"<<endl;
        vector<int> az(length);
        fill(az.begin(), az.end(),0);
        while(1){
            guess.clear();
            for(int i=0;i<length;i++){
                int t;
                cin>>t;
                guess.push_back(t);
            }
            if(guess == az){
                break;
            }
            int right = 0;
            map<int,int> mp;
            for(int i=0;i<length;i++){
                if(ans[i]==guess[i]){
                    right++;
                }else{
                    mp[ans[i]] = mp[ans[i]] +1;
                }
            }
            int loss = 0;
            for(int i=0;i<length;i++){
                if(ans[i]!=guess[i] and mp[guess[i]]>0){
                    loss++;
                    mp[guess[i]] -=1;
                }
            }
            cout<<"    ("<<right<<","<<loss<<")"<<endl;
        }
    }
    return 0;
}
