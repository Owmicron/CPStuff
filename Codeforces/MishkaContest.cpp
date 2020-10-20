#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll p[101];
int main(){
    ll n,k;
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        cin>>p[i];
    }
    ll ans=0;
    ll l=1;ll r=n;
    for(ll i=1;i<=n;i++){
        if(p[l]<=k){ans++;l++;}
        else if(p[r]<=k){ans++;r--;}
        else{break;}
    }
    cout<<ans<<endl;
}

