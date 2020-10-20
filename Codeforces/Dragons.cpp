#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
pair<ll,ll>d[2000];
int main(){
    ll n,s;
    cin>>s>>n;
    for(ll i=1;i<=n;i++){
        cin>>d[i].first>>d[i].second;
    }
    sort(d+1,d+1+n);

    for(ll i=1;i<=n;i++){
        if(s>d[i].first){s+=d[i].second;}
        else{s=-1;break;}

    }
    if(s>0){cout<<"YES";}
    else{cout<<"NO";}
}
