#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
bool isprime[300000],isused[200000];
ll prime[300000],nprime,highest[200000],n,d;
void genprime(){
    for(ll i=2;i<=200000;i++){
        isprime[i]=true;
    }
    for(ll i=2;i<=200000;i++){
        if(isprime[i]){
            nprime++;
            prime[nprime]=i;
            for(ll j=i*2;j<=200000;j+=i){
                isprime[j]=false;
            }
        }
    }
}
void factorize(ll x){
    ll now=0;
    ll f=0;
    while(x>1){
        for(ll i=1;i<=nprime;i++){
            if(x % prime[i] == 0){
                if(prime[i]!=now){
                    now=prime[i];
                    f=0;
                    f++;
                    isused[now]=true;
                    if(f>highest[now]){highest[now]=f;}
                }
                else{
                    f++;
                    if(f>highest[now]){highest[now]=f;}
                }
                x/=prime[i];break;
            }
        }
    }
}
ll sqr(ll a, ll b){
    ll c=1;
    for(ll i=1;i<=b;i++){
        c*=a;
    }
    return c;
}
int main(){
    genprime();
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>d;
        factorize(d);
    }
    ll ans=1;
    for(ll i=1;i<=nprime;i++){
        if(isused[prime[i]]){
            ans*=sqr(prime[i],highest[prime[i]]);
        }
    }
    cout<<ans<<endl;
}
