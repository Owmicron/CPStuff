#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
bool isprime[1000000];
ll prime[1000000],nprime,t,k;
void genprime(){
    for(ll i=2;i<=1000000;i++){
        isprime[i]=true;
    }
    for(ll i=2;i<=1000000;i++){
        if(isprime[i]){
            nprime++;
            prime[nprime]=i;
            for(ll j=i*2;j<=1000000;j+=i){
                isprime[j]=false;
            }
        }
    }
}
int main(){
    genprime();
    cin>>t;
    for(ll i=1;i<=t;i++){
        cin>>k;cout<<prime[k]<<endl;
    }
}
