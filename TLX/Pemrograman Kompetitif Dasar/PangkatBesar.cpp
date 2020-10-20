#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll a,b,c;bool zero;
ll p(ll x){
    if(x==1){
        if(a>=1000000){zero=true;return a%1000000;}
        return a;
    }
    else{
        if(x%2==1){
            ll z=p(x/2);
            ll ans = (z*z*(a%1000000));
            if(ans>=1000000){zero=true;ans%=1000000;}
            return ans;
        }
        else{
            ll z=p(x/2);
            ll ans = (z*z);
            if(ans>=1000000){zero=true;ans%=1000000;}
            return ans;
        }
    }
}
void zz(ll x){
    for(ll i=1;i<=x;i++){cout<<0;}
}
void outp(){
    if(!zero){cout<<c<<endl;}
    else{
        if(c<1){zz(6);cout<<endl;}
        else if(c<10){zz(5);cout<<c<<endl;}
        else if(c<100){zz(4);cout<<c<<endl;}
        else if(c<1000){zz(3);cout<<c<<endl;}
        else if(c<10000){zz(2);cout<<c<<endl;}
        else if(c<100000){zz(1);cout<<c<<endl;}
        else{cout<<c<<endl;}

    }
}
int main(){
    cin>>a>>b;
    c=p(b);outp();
}
