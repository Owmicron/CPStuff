#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll b[200000],n,q,x,y,l,r;
int main(){
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){cin>>b[i];}
    cin>>q;
    for(ll i=1;i<=q;i++){
        cin>>x>>y;
        l=lower_bound(b+1,b+n,x+1)-b;
        r=upper_bound(b+1,b+n,y)-b;
        if(x+1>b[n]){l=n+1;}
        if(b[r]>y){r--;}
        //cout<<l<<" "<<r<<endl;
        cout<<r-l+1<<endl;
    }

}
