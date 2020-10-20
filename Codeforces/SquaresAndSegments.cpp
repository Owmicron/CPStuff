#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll s=2,n,ans;
ll memo[100000];
bool calc[100000];
ll mx(ll x){
    if(!calc[x]){
        ll a=x/2;
        ll b=x-a;
        memo[x]=a*b;
        return memo[x];
    }
    else{
        return memo[x];
    }
}
int main(){
    cin>>n;
    while(1>0){
        if(mx(s)>=n){ans=s;break;}
        s++;
    }
    cout<<ans<<endl;
}
