#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll a,b,c,d,e,f,t;
ll gcd(ll x, ll y){
    if(y>x){swap(x,y);}
    ll z = x%y;
    while(z>0){
        x=y; y=z;
        z=x%y;
    }
    return y;
}
int main(){
    cin>>a>>b;
    cin>>c>>d;

    t = gcd(a,b);
    a/=t;b/=t;
    t = gcd(c,d);
    c/=t;d/=t;

    t = gcd(b,d);
    f = (b/t)*d;

    e = ((f/b)*a) + ((f/d)*c);
    t = gcd(e,f);
    e/=t;f/=t;
    cout<<e<<" "<<f<<endl;
}
