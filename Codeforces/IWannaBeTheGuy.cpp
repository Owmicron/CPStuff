#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,p,q,t,lvl[101];
bool pass(ll x){
    for(ll i=1;i<=x;i++){
        if(!lvl[i]){return false;}
    }
    return true;
}
int main(){
    cin>>n;
    cin>>p;
    for(ll i=1;i<=p;i++){
        cin>>t;lvl[t]=true;
    }
    cin>>q;
    for(ll i=1;i<=q;i++){
        cin>>t;lvl[t]=true;
    }

    if(pass(n)){cout<<"I become the guy.";}
    else{cout<<"Oh, my keyboard!";}
}
