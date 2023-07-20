#include<bits/stdc++.h>

using namespace std;

const char ENDLINE = '\n';

typedef struct {
    int hour;
    int minute;
    int second;
} timer;

int main(void){
    ios::sync_with_stdio(false);
    int caseNum;
    cin >> caseNum;
    while(caseNum--){
        timer t1, t2;
        cin >> t1.hour >> t1.minute >> t1.second;
        cin >> t2.hour >> t2.minute >> t2.second;
        timer resp;
        resp.second = (t1.second + t2.second) % 60;
        resp.minute = (t1.minute + t2.minute + (t1.second + t2.second)/60) %60;
        resp.hour = t1.hour + t2.hour + (t1.minute + t2.minute) /60;
        cout << resp.hour << " " << resp.minute << " " << resp.second << ENDLINE;
    }
    return 0;
}
