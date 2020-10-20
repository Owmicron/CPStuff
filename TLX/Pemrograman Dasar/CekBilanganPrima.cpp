#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
bool isprime[1000001];
void genprime(ll x){
    for(ll i=2;i<=x;i++){
        isprime[i]=true;
    }
    for(ll i=2;i<=x;i++){
        if (isprime[i]){
            for(ll j=i*2;j<=x;j+=i){
                isprime[j]=false;
            }
        }
    }
}
int main(){
    genprime(1000000);
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        ll t;
        cin>>t;
        if (isprime[t]){cout<<"YA";}
        else{cout<<"BUKAN";}
        cout<<endl;
    }

}
