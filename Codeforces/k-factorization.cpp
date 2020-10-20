#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
long n,k,p,prime[100001],f[100001];
bool isprime[100001];
void sieve(long x){
    for(ll i=2;i<=x;i++){
        isprime[i]=true;
    }

    for(ll i=2;i<=x;i++){
        if(isprime[i]){
            isprime[i]=true;
            for(ll j=2*i;j<=x;j+=i){
                isprime[j]=false;
            }
        }
    }
    for(ll i=1;i<=x;i++){
        if (isprime[i]){
            p++;
            prime[p]=i;
        }

    }
}
long s;
queue <long> fac;
int main(){
    cin>>n>>k;
    sieve(100000);
    long c;
    c=1;
    while(n > 1){
        if(n % prime[c] == 0){
            n/=prime[c];
            if(f[prime[c]] == 0){
                fac.push(prime[c]);
            }
            f[prime[c]]++;
            s++;
        }
        else{
            c++;
        }
    }

    if(s<k){
        cout<<-1;
    }
    else{
        while(k>1){
            if(f[fac.front()] > 0){
                f[fac.front()]--;
                cout<<fac.front()<<" ";
                k--;
            }
            else{
                fac.pop();
            }
        }
        ll sum=1;
        while(!fac.empty()){
            if(f[fac.front()] > 0){
                f[fac.front()]--;
                sum*=fac.front();
            }
            else{
                fac.pop();
            }
        }
        cout<<sum;
    }

}
