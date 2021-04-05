#include<bits/stdc++.h>
using namespace std;
int main(void){
    char c;
    bool t = true;
    while((c=getchar())!=EOF){
        if(c=='"'){
            if(t){
                cout<<"``";
            }else{
                cout<<"''";
            }
            t = not t;
        }else{
            cout<<c;
        }
    }
    return 0;
}
