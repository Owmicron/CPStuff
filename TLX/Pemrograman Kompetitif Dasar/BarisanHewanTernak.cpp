#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,a[200000],q;
ll src(ll x){
    ll l=1; ll r=n;
    ll m=(l+r)/2;
    bool found=false;
    while((l<=r)&&(!found)){
        m = (l+r)/2;
        if(x<=a[m]){
            if(x>a[m-1]){
                found=true;
            }
            else{
                r=m-1;
            }
        }
        else{
            l=m+1;
        }
    }
    return m;
}
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        ll t;cin>>t;
        a[i]=a[i-1]+t;
    }
    cin>>q;
    for(ll i=1;i<=q;i++){
        ll t;cin>>t;
        cout<<src(t)<<endl;
    }
}
