#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int main(){
    ll n,mx,mn;
    mx = -100001;
    mn = 100001;
    cin>>n;
    for(ll i=1;i<=n;i++){
        ll x;cin>>x;
        if(x>mx){mx=x;}
        if(x<mn){mn=x;}
    }
    cout<<mx<<" "<<mn<<endl;

}
