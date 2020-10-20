#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,x[20000],y[20000],ans;
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++){cin>>x[i];}sort(x+1,x+n+1);
    for(ll i=1;i<=n;i++){cin>>y[i];}sort(y+1,y+n+1);
    for(ll i=1;i<=n;i++){ans+=x[i]*y[n+1-i];}
    cout<<ans<<endl;
}
