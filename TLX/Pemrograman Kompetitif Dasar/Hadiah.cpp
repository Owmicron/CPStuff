#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll a,b,c,n,r,ans;
ll p(ll x,ll y,ll z){
    if(y==1){
        return x%z;
    }
    else if(y==0){return 1;}
    else{
        ll w = p(x,y/2,n);
        if(y%2==1){
            ll temp = ((w%z)*(w%z))%z;
            return (temp*(x%z))%z;
        }
        else{
            return ((w%z)*(w%z))%z;
        }
    }
}
int main(){
    cin>>a>>b>>c>>n;
    ans=a;
    for(ll i=1;i<=c;i++){
        ans=p(ans,b,n);
    }
    ans++;
    cout<<ans<<endl;
}
