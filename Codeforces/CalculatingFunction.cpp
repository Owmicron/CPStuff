#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll f(ll x){
    ll u1=1;ll un=x-1;
    if(un%2 != 1){un--;}
    ll n=(un-u1+2)/2;
    ll odd,a,b;
    a=n; b=(u1+un);
    if(a%2==0){a/=2;}
    else{b/=2;}
    odd=a*b;

    u1=2;un=x-1;
    if(un%2 != 0){un--;}
    n=(un-u1+2)/2;
    ll even;
    a=n; b=(u1+un);
    if(a%2==0){a/=2;}
    else{b/=2;}
    even=a*b;

    ll ans=even-odd;
    if(x % 2 == 1){ans+=-x;}
    else{ans+=x;}

    return ans;
}
ll n;
int main(){
    cin>>n;
    cout<<f(n);
}
