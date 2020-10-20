#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str s,c[201];
ll k,l,de,du,temp,det[200],dup[200];
int main(){
    cin>>s;
    cin>>k;
    for(ll i=0;i<s.size();i++){
        if(s[i] == '?'){de++;det[de]=l;}
        else if(s[i] == '*'){du++;dup[du]=l;de++;det[de]=l;}
        else{l++;c[l]=s[i];}
    }
    if(l==k){for(ll i=1;i<=l;i++){cout<<c[i];}}
    else if(l>k){
        temp=l;
        for(ll i=1;i<=de;i++){
            c[det[i]] = "";
            temp--;
            if(temp==k){break;}
        }
        if(temp==k){
            for(ll i=1;i<=l;i++)cout<<c[i];
        }
        else{cout<<"Impossible";}
    }
    else{
        if(du>0){
            char t;
            t = c[dup[1]][0];
            for(ll i=1;i<=k-l;i++){
                c[dup[1]]+=t;
            }
            for(ll i=1;i<=l;i++)cout<<c[i];
        }
        else{cout<<"Impossible";}
    }
}
