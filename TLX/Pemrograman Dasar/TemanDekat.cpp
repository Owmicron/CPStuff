#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll x[1001],y[1001],d,n;
ll ex(ll a,ll b){
    ll sum=1;
    for(ll i=1;i<=b;i++){
        sum*=a;
    }
    return sum;
}
ll t(ll i,ll j){
    return ( ex(abs(x[j]-x[i]),d)+ex(abs(y[j]-y[i]),d) );
}
int main(){
    cin>>n>>d;
    for(ll i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    ll mx,mn;
    mx=-100000000;
    mn=100000000;
    for(ll i=1;i<=n;i++){
        for(ll j=i+1;j<=n;j++){
            ll v=t(i,j);
            if(v<mn){mn=v;}
            if(v>mx){mx=v;}
        }
    }
    cout<<mn<<" "<<mx<<endl;
}
