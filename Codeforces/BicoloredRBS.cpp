#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
vector<int>open,close;
str s;
bool blue;
int ans[300000],n;
int main(){
    cin>>n;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(')open.push_back(i);
        if(s[i]==')')close.push_back(i);
    }
    for(int i=0;i<open.size();i++){
        int idx1 = open[i];
        int idx2 = close[i];
        if(blue){ans[idx1]=0;ans[idx2]=0;}
        else{ans[idx1]=1;ans[idx2]=1;}
        blue = not blue;
    }
    for(int i=0;i<s.size();i++)cout<<ans[i];
}
