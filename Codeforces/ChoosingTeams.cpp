#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,k,t[3000],ans;
bool eligible(ll x){
    bool e=true;
    for(ll i=(x-1)*3+1;i<=(x-1)*3+3;i++){
        if(t[i]+k>5){e=false;break;}
    }
    return e;
}
int main(){
    cin>>n>>k;
    for(ll i=1;i<=n;i++)cin>>t[i];
    sort(t+1,t+1+n);
    for(ll i=1;i<=n/3;i++){
        if(eligible(i)){ans++;}
    }
    cout<<ans<<endl;
}
