#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll k,r,ans;
int main(){
    cin>>k>>r;
    for(ll i=1;i<=10;i++){
        ll temp = k*i;
        temp%=10;
        if((temp==0)||(temp==r)){ans=i;break;}
    }
    cout<<ans<<endl;
}
