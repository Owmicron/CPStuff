#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll t,L,v,l,r;
int main(){
    cin>>t;
    for(ll cases=1;cases<=t;cases++){
        cin>>L>>v>>l>>r;
        ll a,b,c;
        a = L/v;
        b = (l-1)/v;
        c = r/v;
        ll ans = a - (c-b);
        cout<<ans<<endl;
    }

}
