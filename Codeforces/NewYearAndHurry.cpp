#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll s[20],n,k;
int main(){
    for(ll i=1;i<=10;i++)s[i]=s[i-1]+5*i;
    cin>>n>>k;
    k=240-k;
    ll ans=0;
    for(ll i=1;i<=n;i++){
        if(s[i]>k)break;
        else{ans=i;}
    }
    cout<<ans<<endl;
}
