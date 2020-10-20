#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
bool isprime[1000001];
ll prime[100000];
ll d[1000001];
ll np;
void genprime(ll x){
    for(ll i=2;i<=x;i++){
        isprime[i]=true;
    }
    for(ll i=2;i<=x;i++){
        if (isprime[i]){
            for(ll j=i*2;j<=x;j+=i){
                isprime[j]=false;
                d[j]=i;
            }
        }
    }
}
int main(){
    genprime(1000000);
    ll n,a,b;
    cin>>n;

    for(ll i=1;i<=n;i++){
        ll t;
        cin>>t;
        if(isprime[t]){cout<<"YA";}
        else{
            if (t==1){cout<<"YA";}
            else if (isprime [ (t / d[t]) ]){cout<<"YA";}
            else{cout<<"BUKAN";}
        }
        cout<<endl;

    }

}
