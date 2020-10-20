#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int main(){
    ll s,a,b,c,t;
    cin>>t;
    for(ll i=1;i<=t;i++){
    cin>>s>>a>>b>>c;
    ll ans = s/c + ((s/c)/a) * b;
    cout<<ans<<endl;
    }

}
