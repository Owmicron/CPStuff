#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,a[2000000],ans;
int main(){
    cin>>n;
    ll mx=-1;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>mx){mx=a[i];}
    }
    for(ll i=1;i<=n;i++){
        ans += abs(mx-a[i]);
    }
    cout<<ans<<endl;
}
