#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
bool isprime[1000000];
ll prime[1000000],np,n,q;
void genprime(){
    for(ll i=2;i<=1000000;i++){
        isprime[i]=true;
    }
    for(ll i=2;i<=1000000;i++){
        if(isprime[i]){
            np++;prime[np]=i;
            for(ll j=i*2;j<=1000000;j+=i){
                isprime[j]=false;
            }
        }
    }
}

//bool tprime(ll x){
//    if(isprime[x]){return false;}
//    for(ll i=1;i<=np;i++){
//        if(prime[i]>x){return false;}
//        double c = log (x) / log(prime[i]);
//        //cout<<prime[i]<<endl<<c<<" "<<floor(c)<<endl<<endl;
//        cout<<c<<" "<<floor(c)<<" "<<c-floor(c)<<endl;
//        if(c == floor(c) ){return true;}
//    }
//    return false;
//}
ll tp[100000],am;
void tprime(){
    for(ll i=1;i<=np;i++){
//        for(ll j=prime[i]*prime[i];j<=1000000000000;j*=prime[i]){
//                am++;
//                tp[am]=j;
//        }
        am++;
        tp[am]=prime[i]*prime[i];
    }
}
bool src(ll x){
    ll l=1;
    ll r=am;
    ll m= (l + r)/2;
    bool found=false;
    while(l<=r){
        //cout<<l<<" "<<r<<" "<<m<<" "<<tp[m]<<endl;
        m = (l+r)/2;
        if(tp[m]>x){r = m-1;}
        else if(tp[m]<x){l = m+1;}
        else{found=true;break;}
    }
    if(tp[m]==x){found=true;}
    return found;
}
int main(){
    genprime();
    tprime();
    sort(tp+1,tp+1+am);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>q;
        if(src(q)){cout<<"YES";}
        else{cout<<"NO";}
        cout<<endl;
    }
//    for(ll i=1;i<=20;i++){cout<<tp[i]<<endl;}cout<<am<<endl;
}
