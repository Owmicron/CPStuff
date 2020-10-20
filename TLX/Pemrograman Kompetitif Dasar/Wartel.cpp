#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,q;
str s[100001],p[100001];
void src(str x){
    ll l=1;
    ll r=n;
    ll found=0;
    while((l<=r)&&(found==0)){
        ll m=(l+r)/2;
        if(x>s[m]){l=m+1;}
        else if(x<s[m]){r=m-1;}
        else{found=m;}
    }
    if(found==0){cout<<"NIHIL"<<endl;}
    else{cout<<p[found]<<endl;}
}
int main(){
    cin>>n>>q;
    for(ll i=1;i<=n;i++){
        cin>>s[i]>>p[i];
    }
    for(ll i=1;i<=q;i++){
        str t;cin>>t;
        src(t);
    }
}
