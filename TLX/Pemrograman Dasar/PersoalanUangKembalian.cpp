#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll coin[501],n,memo[50001];
bool calc[50001];
ll solve (ll x){
    if(x==0){return 0;}
    if(x<0){return 100000;}
    if(calc[x]){return memo[x];}
    ll best = 100000;
    for(ll i=n;i>=1;i--){
        best = min (best, solve(x-coin[i])+1);
    }
    calc[x]=true;
    memo[x]=best;
    return best;
}
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>coin[i];
    }
    sort(coin+1,coin+n+1);
    ll k;
    cin>>k;
    ll ans=solve(k);
    if(ans > 50000){ans=-1;}
    cout<<ans<<endl;



}
