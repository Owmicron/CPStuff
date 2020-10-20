#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,a[200],q,memo[102][102];
ll m=26101991;
bool vis[102][102];
ll bla(ll x,ll y, ll z){
    return a[x]*a[y]*a[z];
}
ll f(ll l, ll r){
    if(l==r){return 0;}
    if(!vis[l][r]){
        for(ll i=l;i<r;i++){
            if(i==l){
                memo[l][r]=f(l,i)+f(i+1,r)+bla(l,i+1,r+1);
            }
            else{
                memo[l][r]=min(memo[l][r], f(l,i)+f(i+1,r)+bla(l,i+1,r+1));
            }
        }
        vis[l][r]=true;
        return memo[l][r];
    }
    else{
        return memo[l][r];
    }
}
bool v[102];
ll mem[102];
ll w(ll x){
    if(x<=2){return 1;}
    if(!v[x]){
        for(ll i=1;i<x;i++){
            mem[x]+=((w(i)%m)*(w(x-i)%m))%m;
        }
        v[x]=true;
        mem[x]%=m;
        return mem[x];
    }
    else{
        return mem[x];
    }
}
ll o[102][102];
bool calc[102][102];
ll opt(ll l, ll r){
    if(r-l <= 1){return 1;}
    else{
        if(!calc[l][r]){
            ll ans = 0;
            for(ll i=1;i<r;i++){
                if(memo[l][i] + memo[i+1][r] + bla(l,i+1,r+1) == memo[l][r]){
                    ll temp = (opt(l,i)%m * opt(i+1,r)%m)%m;
                    ans += temp % m;
                }
            }
            ans%=m;
            o[l][r]=ans;
            calc[l][r]=true;
            return ans;
        }
        else{return o[l][r];}
    }
}
int main(){
    cin>>n;
    for(ll i=1;i<=n+1;i++)cin>>a[i];
    cin>>q;
    if(q==1){cout<<f(1,n)<<endl;}
    else if(q==2){
        f(1,n);
        cout<<opt(1,n)%m<<endl;
    }
    else{cout<<w(n)%m<<endl;}


}
