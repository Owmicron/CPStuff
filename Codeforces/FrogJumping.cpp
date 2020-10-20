#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int main(){
    ll a,b,k,ans,t;
    cin>>t;
    for(ll i=1; i<=t; i++){
        cin>>a>>b>>k;
        ans = (k/2)*a - (k/2)*b;
        if(k%2==1){ans+=a;}
        cout<<ans<<endl;

    }
}


