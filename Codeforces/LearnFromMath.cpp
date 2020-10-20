#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
bool isprime[1000000];
void genprime(ll x){
    for(ll i=1;i<=x;i++){
        isprime[i]=true;
    }
    for(ll i=2;i<=x;i++){
        if(isprime[i]){
            for(ll j=2*i;j<=x;j+=i){
                isprime[j]=false;
            }
        }
    }
}
int main(){
    ll n;
    cin>>n;
    genprime(n);
    ll a,b;
    for(ll i=1;i<=n;i++){
        if(!isprime[i]){
            if(!isprime[n-i]){cout<<i<<" "<<n-i;break;}
        }

    }
}
