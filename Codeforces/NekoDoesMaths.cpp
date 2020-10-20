#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int a,b,ans;
ll k;
vector< pair<int,int> > mn;
ll gcd (ll x, ll y){
    if(x<y)swap(x,y);
    ll z = x%y;
    while(z>0){
        x=y;
        y=z;
        z=x%y;
    }
    return y;
}
ll lcm (ll x, ll y){
    ll g = gcd(x,y);
    return (x*y)/g;
}
int main(){
    scanf("%d %d",&a,&b);
    if(a>b)swap(a,b);
    ll mn = lcm(a,b);
    for(int i=1;i<=sqrt(b-a);i++){
        if((b-a)%i == 0){
            ll temp,t,l;
            t = i;
            temp = t - (a%t);
            l = lcm(a+temp,b+temp);
            if(l < mn){mn = l;k=temp;}
            else if(l == mn){if(t<k)k=temp;}

            t = (b-a)/i;
            temp = t - (a%t);
            l = lcm(a+temp,b+temp);
            if(l < mn){mn = l;k=temp;}
            else if(l == mn){if(t<k)k=temp;}
        }
    }

    printf("%lld\n",k);

}
