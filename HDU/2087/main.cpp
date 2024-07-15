#include<bits/stdc++.h>

using namespace std;
const char ENDLINE = '\n';
/*
 * kmp板子题
 * 求出目标字符串的匹配数量(无交叉)
 * */

vector<int> buildNext(const string& pattern){
    //前缀: 包含首字符但不包含尾字符的所有子串
    //后缀: 包含尾字符但不包含首字符的所有子串
    //next数组:使得 next[i]=k 表示 p[0]开头长度为前缀串与p[i]结尾的后缀串相同的最大长度为k
    vector<int> next = vector<int>(pattern.size(), 0);
    next[0] = 0;
    int prefixPos = 0;
    int tailPos = 1;
    while(tailPos < pattern.size()){
        if(pattern[tailPos] == pattern[prefixPos]){
            //匹配成功, 串长度就是前缀下标+1(从0开始)
            next[tailPos] = prefixPos +1;
            tailPos++;
            prefixPos++;
        }else if(prefixPos != 0){
            //前后缀匹配非开头失败
            //至少说明前面的部分是一样的
            //跳过公共前后缀,比对剩余部分(有点类似接下来的kmp匹配逻辑)
            //-1: 当前字符还要比，只是前面的不用比了
            prefixPos = next[prefixPos-1];
        }else{
            //如果开头就匹配失败，说明没有公共前后缀
            //长度就是0
            next[tailPos] = 0;
            tailPos += 1;
        }
    }
    return next;
}

int kmpMatch(const string& text, const string& pattern){
    vector<int> next = buildNext(pattern);

    int matchCount = 0;
    int patternPos = 0;
    int textPos = 0;
    while(textPos < text.size()){
        if(text[textPos] == pattern[patternPos]){
            textPos++;
            patternPos++;
            if(patternPos == pattern.size()){
                matchCount++;
                patternPos = 0;
            }
        }else if(patternPos != 0){
            /* 只有在非开头，才有去找前缀的必要
             * 非开头匹配失败，说明前面的部分匹配成功
             * 通过找匹配成功部分的最大后缀与前缀相同的部分，来跳过重复匹配
             * -1: 因为当前字符还要比，只是前面的不用比了
             */
            patternPos = next[patternPos-1];
        }else{
            //模式串开头失败，直接下一个字符
            textPos += 1;
        }
    }
    return matchCount;
}
int main(void){
    ios::sync_with_stdio(false);
    string text, pattern;
    while(cin>> text){
        if(text == "#"){
            break;
        }
        cin >> pattern;
        cout << kmpMatch(text, pattern) << ENDLINE;
    }
}
