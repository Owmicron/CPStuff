#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll lef[200000],righ[200000],a[200000];
int n;
ll gcd (ll a, ll b){
    if(a<b)swap(a,b);
    ll c = (a%b);
    while(c>0){
        a = b;
        b = c;
        c = a%b;
    }
    return b;
}
vector <ll> candidate;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    lef[1]=a[1];
    for(int i=2;i<=n;i++){
        lef[i] = gcd(a[i],lef[i-1]);
    }
    righ[n]=a[n];
    for(int i=n-1;i>=1;i--){
        righ[i] = gcd(a[i],righ[i+1]);
    }

    ll mx = -1;
    for(int i=1;i<=n;i++){
        ll g;
        if(i==1){g = righ[2];}
        else if(i==n){g=lef[n-1];}
        else {
            g = gcd(lef[i-1],righ[i+1]);
        }
        mx = max(mx,g);
    }
    cout<<mx<<endl;
}
