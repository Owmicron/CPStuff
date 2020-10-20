#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll dp[200000],n;
ll v[200000];
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        int temp;
        scanf("%lld",&temp);
        v[temp]+=temp;
    }
    dp[1]=v[1];
    dp[2]=v[2];
    for(int i=3;i<=100000;i++){
        dp[i]=max(dp[i-2]+v[i],dp[i-3]+v[i]);
    }
    ll mx=-1;
    for(int i=1;i<=100000;i++){
        mx = max(mx,dp[i]);
    }
    printf("%lld\n",mx);
}
