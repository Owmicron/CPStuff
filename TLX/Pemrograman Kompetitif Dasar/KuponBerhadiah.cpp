#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,x,t,m,ans;
int main(){
    cin>>n>>x;
    ans=1000000;
    m=1000000;
    for(ll i=1;i<=n;i++){
        cin>>t;
        if(abs(x-t)<m){m=abs(x-t);ans=t;}
        else if(abs(x-t)==m){if(t<ans){ans=t;}}
    }
    cout<<ans<<endl;
}
