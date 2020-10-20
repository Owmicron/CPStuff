#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int t,k;
ll md = 1000000007;
ll memo[200000];
bool calc[200000];
ll dp (ll x){
    if(x==0)return 0;
    else if(x<0)return -1;
    else if (calc[x]) return memo[x];
    else{
        ll ans = 0;
        calc[x]=true;
        ans = (((1+dp(x-1))%md) + (1+(dp(x-k))%md)) %md;
        memo[x]=ans;
        return ans;
    }
}
int main(){
    scanf("%d %d",&t,&k);
    for(int cases=1;cases<=t;cases++){
        ll l,r;
        scanf("%lld %lld",&l,&r);
        ll tot=0;
        tot = ((dp(r) % md) - (dp(l-1) % md))%md;
        if(tot<0){tot = dp(r) + md - dp(l-1);}

        printf("%lld\n",tot);
    }
}
