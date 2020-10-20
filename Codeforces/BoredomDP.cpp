#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,a[200000],memo[200000],f[200000],v[200000];
bool calc[200000],used[200000];
ll dp(ll x){
    if(x>a[n]){return 0;}
    else{
        if(!calc[x]){
            ll base=x;
            while(f[x]==0){
                    x++;
            }
            if(x>a[n]){return 0;}
            ll ans = max(dp(x+2)+v[x],dp(x+3)+v[x]);
            //cout<<x<<" "<<ans<<endl;
            for(ll i=base;i<=x;i++){
                calc[i]=true;memo[i]=ans;
            }
            return ans;
        }
        else{return memo[x];}
    }
}
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++){cin>>a[i];f[a[i]]++;}
    sort(a+1,a+1+n);
    for(ll i=1;i<=a[n];i++){
        v[i]=f[i]*i;
    }
    ll first,second;
    first=a[1];
    second=first;
    for(ll i=2;i<=n;i++){
        if(a[i]!=first){second=a[i];break;}
    }
    //for(ll i=1;i<=n;i++){cout<<f[i]<<endl;}
    cout<<max(dp(first),dp(second))<<endl;
}
