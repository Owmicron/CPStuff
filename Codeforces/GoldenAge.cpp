#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10001],b[10001],x,y,l,r,n,m;
int main(){
    cin>>x>>y>>l>>r;
    ll n=1;
    a[n]=1;b[n]=1;
    while(a[n] <= r){
        n++;
        a[n]=a[n-1]*x;
        cout<<a[n]<<endl;
    }

    m=1;
    while(b[m] <= r){
        m++;
        b[m]=b[m-1]*y;
        cout<<b[m]<<endl;
    }
    //cout<<n<<m<<endl;
    vector<ll> u;
    ll x=0;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            //cout<<a[i]<<" "<<b[j]<<endl;
            //cout<<a[i]+b[j]<<endl;
            if(((a[i] + b[j])>=l) && ((a[i] + b[j])<=r)){
                u.push_back(a[i]+b[j]);
            }
        }
    }
    u.push_back(l-1); u.push_back(r+1);
    sort(u.begin(),u.end());
    ll mx=0;
    ll v,w;
    v=u.back();
    u.pop_back();

    ll sum;
    while(!u.empty()){
        w = v;
        v =u.back();
        u.pop_back();
        mx=max(mx,w-v-1);

    }
    cout<<mx;
}
