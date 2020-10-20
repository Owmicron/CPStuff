#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[2000],l[2000],r[2000];
int main(){
    ll n;
    cin>>n;
    ll sum=0;


    for(ll i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    ll m;cin>>m;
    ll mx;
    mx=-1;

    for(ll i=1;i<=m;i++){
        cin>>l[i]>>r[i];
        mx=max(mx,l[i]);mx=max(mx,r[i]);
    }

    if(sum<=mx){
        for(ll i=1;i<=m;i++){
            if(sum<=l[i]){
                cout<<l[i];
                break;
            }
            else if(sum<=r[i]){
                cout<<min(sum,r[i]);
                break;
            }
        }
    }
    else{cout<<-1;}
}
