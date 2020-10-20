#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll a,b,k,x;
ll f(ll x){
    return abs(a*x+b);
}
int main(){
    cin>>a>>b>>k>>x;
    ll ans=x;
    for(ll i=1;i<=k;i++){
        ans=f(ans);
    }
    cout<<ans<<endl;
}
