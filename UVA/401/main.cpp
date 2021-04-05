#include<bits/stdc++.h>
using namespace std;
bool IsPalindrome(const string &s){
    string temp = s;
    reverse(temp.begin(), temp.end());
    return temp == s;
}
bool IsMirror(const string &s){
    string temp = s;
    map<char, int> dict;
    string leagal="AMYZO12E3S5HTIUJV8WLX";
    string change="AMY5O1S3E2ZHTIULV8WJX";
    for(int i=0;i<leagal.length();i++){
        dict[leagal[i]]=change[i];
    }
    string illegal="BNCDPQFR4G67K9";
    for(const auto&i:illegal){
        dict[i] = -1;
    }
    for(int i=0;i<temp.length();i++){
        int t = dict[temp[i]];
        if(t == -1){
            return false;
        }
        temp[i] = t;
    }
    reverse(temp.begin(),temp.end());
    return temp == s;
}
int main(void){
    ios::sync_with_stdio(false);
    string s;
    while(cin>>s){
        bool mir = IsMirror(s);
        bool pal = IsPalindrome(s);
        if(mir and pal){
            cout<<s<<" -- is a mirrored palindrome."<<endl;
        }else if(mir and (pal==false)){
            cout<<s<<" -- is a mirrored string."<<endl;
        }else if(pal){
            cout<<s<<" -- is a regular palindrome."<<endl;
        }else{
            cout<<s<<" -- is not a palindrome."<<endl;
        }
        cout<<endl;
    }
    return 0;
}
