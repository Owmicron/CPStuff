#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,f[30];str s,ans;
bool h;
void reset(){
    for(ll i=1;i<=26;i++)f[i]=0;
}
str diverse(ll start,ll length){
    str x="";
    for(ll i=start;i<=start+length-1;i++){
        x+=s[i];
    }
    return x;
}
bool isdiverse(ll start,ll length){
    bool d=true;
    for(ll i=start;i<=start+length-1;i++){
        f[int(s[i])-95]++;
        if(f[int(s[i])-95]>(length)/2){d=false;break;}
    }
    return d;
}
int main(){
    cin>>n;
    cin>>s;
    for(ll i=2;i<=s.size();i++){
        for(ll j=1;j<=s.size()-i+1;j++){
            reset();
            if(isdiverse(j-1,i)){h=true;ans=diverse(j-1,i);break;}

        }
        if(h){break;}
    }
    if(h){cout<<"YES"<<endl<<ans;}
    else{cout<<"NO"<<endl;}
}
