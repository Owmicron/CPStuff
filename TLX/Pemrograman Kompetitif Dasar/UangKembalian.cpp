#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,memo[60000],coin[501],k;
bool vis[60000];
ll dp(ll x){
    if(x==0){return 0;}
    if(!vis[x]){
        ll ans=100000;
        for(ll i=1;i<=n;i++){
            if(coin[i]<=x){
                ans = min(ans,dp(x-coin[i])+1);
            }
        }
        vis[x]=true;
        memo[x]=ans;
        return ans;
    }
    else{
        return memo[x];
    }
}
int main(){
    cin>>n;for(ll i=1;i<=n;i++)cin>>coin[i];
    cin>>k;
    ll z=dp(k);if(z>50000){z=-1;}
    cout<<z<<endl;
}
