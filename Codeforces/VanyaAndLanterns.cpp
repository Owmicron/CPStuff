#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,l,a[1002];
int main(){
    cin>>n>>l;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);

    double m=-1;
    for(ll i=2;i<=n;i++){
        ll temp = a[i]-a[i-1];
        if(temp>m){m=temp;}
    }
    m/=2.0;
    if(a[1] > m){m=a[1];}
    if(l - a[n] > m){m=l-a[n];}
    cout<<fixed<<setprecision(10)<<m<<endl;
}
