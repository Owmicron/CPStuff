#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int main(){
    ll n;
    cin>>n;
    ll ans = n;
    for(ll i=1;i<n-1;i++){
        ans += 1 + (i * (n-i));
    }
    ans++;
    if(n==1){ans=1;}
    cout<<ans<<endl;
}
