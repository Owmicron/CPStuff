#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,m,b[2000],s[20000],ans;
int main(){
    cin>>n>>m;
    for(ll i=1;i<=n;i++){cin>>b[i];}
    for(ll i=1;i<=m;i++){ll t;cin>>t; s[t]++;}
    sort(b+1,b+n+1);
    for(ll i=1;i<=n;i++){
        if(s[b[i]]>0){ans++;s[b[i]]--;}
        else if(s[b[i]+1]>0){ans++;s[b[i]+1]--;}
    }
    cout<<ans<<endl;
}
