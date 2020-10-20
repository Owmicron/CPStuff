#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll bit[100000],mx,res;
void count_bit_p(ll x){
    ll idx = 1;
    ll pos = 1;
    ll two = 2;

    while(pos<=x){
        mx = max(mx,idx);
        ll r = x-pos+1;
        bit[idx] += (r/two)*pos;
        ll p = r % two;
        //cout<<idx<<" "<<pos<<" "<<two<<" "<<p<<" "<<r<<endl;

        bit[idx] += min(p,two/2);

        idx++;
        pos*=2;
        two*=2;
    }
}
void count_bit_m(ll x){
    ll idx = 1;
    ll pos = 1;
    ll two = 2;

    while(pos<=x){
        ll r = x-pos+1;
        bit[idx] -= (r/two)*pos;
        ll p = r % two;
        //cout<<idx<<" "<<pos<<" "<<two<<" "<<p<<" "<<r<<endl;

        bit[idx] -= min(p,two/2);

        idx++;
        pos*=2;
        two*=2;
    }
}
int main(){
    ll a,b;
    cin>>a>>b;
    count_bit_p(b);
    count_bit_m(a-1);

    ll t = 1;
    for(int i=1;i<=mx;i++){
        if(bit[i]%2==1){res+=t;}
        t*=2;
    }
    cout<<res<<endl;
}
