#include <bits/stdc++.h>
using namespace std;
int lps[200],kmp[200];
string text, pattern;
void build_lps(){
    int i = 1, j = 0;
    lps[0] = 0;
    while(i < pattern.size()){
        if(pattern[i] == pattern[j]) lps[i++] = ++j;
        else{
            if(j > 0) j = lps[j-1];
            else lps[i++] = 0;
        }
    }
}
void build_kmp(){
    int i = 0, j = 0;
    build_lps();
    while(i < text.size()){
        if(text[i] == pattern[j]) {
            kmp[i++] = ++j;
            if(j >= pattern.size()) j = lps[j-1];
        }
        else{
            if(j > 0) j = lps[j-1];
            else kmp[i++] = 0;
        }
    }
}
int main(){
    cin >> pattern;
    //cin >> text;
    build_lps();
    for(int i = 0; i < pattern.size(); ++i) cout << lps[i] << " "; cout << endl;
}
