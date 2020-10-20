#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
bool isprime[1000001];
ll prime[100000],np,n;
ll f[1000000];
void genprime(){
    for(ll i=2;i<=1000000;i++){
        isprime[i]=true;
    }
    for(ll i=2;i<=1000000;i++){
        if(isprime[i]){
            np++;prime[np]=i;
            for(ll j=2*i;j<=1000000;j+=i){
                isprime[j]=false;
            }
        }
    }
}
void factorize(ll x){
    ll last;
    if(x==1){cout<<1<<endl;}
    while(x>1){
        for(ll i=1;i<=np;i++){
            if(x%prime[i] == 0){last=prime[i];x/=prime[i];f[prime[i]]++;break;}
        }
    }
    for(ll i=1;i<=np;i++){
        if(f[prime[i]]>0){cout<<prime[i];}
        if(f[prime[i]]>1){cout<<"^"<<f[prime[i]];}
        if(f[prime[i]]>0){
            if(prime[i]!=last){cout<<" x ";}
            else{cout<<endl;break;}
        }
    }
}
int main(){
    genprime();
    cin>>n;factorize(n);
}
