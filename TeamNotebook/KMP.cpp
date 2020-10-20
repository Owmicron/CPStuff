#include<bits/stdc++.h>
using namespace std;

typedef string str;

str pattern,text;
int lps[200];
int kmp[200];
//longest proper prefix which is also suffix
void build_lps (){
    int j = 0;
    lps[0]=0;
    int i = 1;
    while(i<pattern.size()){
        if(pattern[i]==pattern[j]) lps[i++]=++j;
        else{
            if(j) j = lps[j-1];
            else lps[i++]=0;
        }
    }
}
void kmp_search(){
    int i = 0, j = 0;
    build_lps();
    while(i<text.size()){
        if(text[i]==pattern[j]){
            kmp[i++] = ++j;
            if(j==pattern.size()) j=lps[j-1];
        }
        else{
            if(j!=0) j = lps[j-1];
            else{
                kmp[i++]=0;
            }
        }
    }
}
int main(){

    cin>>pattern;
    cin>>text;

    kmp_search();
    int mx = 0;
    for(int i=0;i<text.size();i++) cout<<kmp[i]<<" ";

}
