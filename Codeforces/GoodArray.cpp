#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,sum[300000],ans;
ll y[300000];
pair <ll,ll> a[300000];
ll s(ll a, ll b){
    return sum[b]-sum[a-1];
}
ll ex(ll c, ll d){
    return sum[n]-a[c].first-a[d].first;
}
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        ll temp;cin>>temp;
        a[i].first=temp;
        a[i].second=i;
    }
    sort(a+1,a+1+n);
    for(ll i=1;i<=n;i++){
        sum[i]=a[i].first+sum[i-1];
    }
    ll tot=sum[n];

    for(ll i=n;i>=1;i--){
        ll big = n;
        if(i==n){big=n-1;}
        if(a[big].first == ex(i,big)){ans++;y[ans]=a[i].second;}

    }
    cout<<ans<<endl;
    for(ll i=1;i<=ans;i++){
        cout<<y[i];
        if(i<ans){cout<<" ";}
        else{cout<<endl;}
    }
}
