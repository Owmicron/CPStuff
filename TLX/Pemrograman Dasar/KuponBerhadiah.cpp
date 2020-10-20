#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll ans;
int main(){
    ll n,x;
    cin>>n>>x;
    ll mn=500000;
    for(ll i=1;i<=n;i++){
        ll temp;
        cin>>temp;
        if(abs(x-temp) < mn){ans=temp;mn = abs(x-temp);}
        else if(abs(x-temp) == mn){
            if(temp<ans){ans=temp;}
        }

    }
    cout<<ans<<endl;

}
