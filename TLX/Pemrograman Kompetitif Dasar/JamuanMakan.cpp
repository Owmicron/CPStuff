#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n;
pair<ll,ll> s[200000];
ll ans,last;
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        ll temp,d;cin>>temp>>d;
        s[i].second=temp;s[i].first=temp+d;
    }
    sort(s+1,s+1+n);
    last=0;
    for(ll i=1;i<=n;i++){
        if(s[i].second >= last){last=s[i].first;ans++;}
    }
    cout<<ans<<endl;
}
