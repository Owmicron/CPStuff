#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,a[101];
bool first(ll x){
    bool c=true;
    for(ll i=1;i<=n;i++){
        if(x*3==a[i]){c = false;break;}
        if(x%2==0){
            if(x/2==a[i]){
                c=false;break;
            }
        }
    }
    return c;
}
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    ll now;
    for(ll i=1;i<=n;i++){
        if(first(a[i])){cout<<a[i];now=a[i];break;}
    }
    for(ll j=1;j<n;j++){

        for(ll i=1;i<=n;i++){

        if((a[i]*3)==now){cout<<" "<<a[i];now=a[i];}
        if((a[i]%2)==0){
            if((a[i]/2) == now){
                cout<<" "<<a[i];
                now=a[i];
            }

        }

        }
    }



}






