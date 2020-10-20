#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,a[10000];
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);

    ll ans=(n-1)/2;
    if(n%2==0){ans++;}
    ans = a[n-ans];

    cout<<ans<<endl;

}
