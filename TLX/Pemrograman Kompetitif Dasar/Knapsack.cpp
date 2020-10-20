#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,k,w[200],h[200],memo[200][3000];
bool vis[200][3000];
ll f(ll x, ll y){
    if(x>k){return 0;}
    else{
        if(vis[x][y]){return memo[x][y];}
        else{
            ll ans = 0;
            //take
            if(w[x]<=y){
                ans = max(ans , h[x]+f(x+1,y-w[x]));
            }
            //dont
            ans = max(ans,f(x+1,y));
            vis[x][y]=true;
            memo[x][y]=ans;
            return ans;
        }
    }
}
int main(){
    cin>>n>>k;
    for(ll i=1;i<=k;i++)cin>>w[i]>>h[i];
    f(1,n);
    for(ll i=1;i<=k;i++){
        if(w[i]<=n){
            if(memo[i][n] == h[i]+memo[i+1][n-w[i]]){
                n-=w[i];
                cout<<i<<endl;
            }
        }
    }
}
