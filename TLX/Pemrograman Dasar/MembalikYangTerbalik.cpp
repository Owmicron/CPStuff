#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll a,b;
ll rev(ll x){
    ll ans=0,r;
    while(x>0){
        r = x%10;
        ans*=10;ans+=r;
        x-=r;x/=10;
    }
    return ans;
}
int main(){
    cin>>a>>b;
    cout<<rev(rev(a)+rev(b))<<endl;
}


