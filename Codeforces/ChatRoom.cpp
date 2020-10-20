#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str s;
int point;
bool h,e,l1,l2,o;
int main(){
    cin>>s;
    for(ll i=0;i<s.size();i++){
        if(s[i]=='h'){h=not h; point=i+1 ;break;}
    }
    for(ll i=point;i<s.size();i++){
        if(s[i]=='e'){e=not e; point=i+1; break;}
    }
    for(ll i=point;i<s.size();i++){
        if(s[i]=='l'){l1=not l1; point=i+1; break;}
    }
    for(ll i=point;i<s.size();i++){
        if(s[i]=='l'){l2=not l2; point=i+1; break;}
    }
    for(ll i=point;i<s.size();i++){
        if(s[i]=='o'){o=not o; point=i+1; break;}
    }

    if(h==1 && e==1 && l1==1 && l2==1 && o==1){
        cout<<"YES";
    }
    else{cout<<"NO";}
}

