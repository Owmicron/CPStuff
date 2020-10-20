#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll c[1000];
int main(){
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>c[i];
    }
    sort(c+1,c+n+1);

    for(ll i=1;i<=n;i++){cout<<c[i];if(i<n){cout<<" ";}}
}
