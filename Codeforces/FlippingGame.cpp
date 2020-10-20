#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,a[101],mx,one;
ll flip(ll l,ll r){
    ll mark=0;
    for(ll i=l;i<=r;i++){
        if(a[i]==0)mark++;
        else{mark--;}
    }return mark;
}
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){one++;}
    }
    for(ll i=1;i<=n;i++){
        for(ll j=i;j<=n;j++){
            ll t=one+flip(i,j);
            if(t>mx){mx=t;}
        }
    }
    cout<<mx<<endl;
}
