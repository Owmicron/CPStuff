#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
bool isprime[1000001];
ll np,prime[100000];
deque <ll>a,b;
void genprime(ll x){
    for(ll i=2;i<=x;i++){
        isprime[i]=true;
    }
    for(ll i=2;i<=x;i++){
        if(isprime[i]){
            np++;prime[np]=i;
            for(ll j=i*2;j<=x;j+=i){
                isprime[j]=false;
            }
        }
    }
}
int main(){
    ll n;
    genprime(1000000);
    cin>>n;
    while(n>1){
        for(ll i=1;i<=np;i++){
            if(n%prime[i]==0){
                if(a.empty()){a.push_front(prime[i]);b.push_front(1);}
                else{
                    if(a.front() == prime[i]){
                        ll t=b.front();
                        b.pop_front();
                        b.push_front(t+1);
                    }
                    else{a.push_front(prime[i]);b.push_front(1);}
                }

                n/=prime[i];
                break;
            }
        }
    }
    while(!a.empty()){
        cout<<a.back();
        if(b.back()>1){cout<<"^"<<b.back();}
        a.pop_back();b.pop_back();
        if(!a.empty()){cout<<" x ";}
        else{cout<<endl;}
    }
}

