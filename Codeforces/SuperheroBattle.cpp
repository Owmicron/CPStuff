#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll h,n,d[300000],sum[300000],ans,mn,idx;
ll rnd (ll x){
    ll hp=0;
    if(x>n){
        hp = (x/n)*sum[n] + sum[x%n];
    }
    else{
        hp = sum[x];
    }
    return h + hp;
}
ll src(){
    ll l=1;
    ll r=1000000000000;
    ll ans=10000000000000;
    while(l<=r){
        ll mid=(l+r)/2;
        if(rnd(mid)<=0 && round(mid-1)>0){ans=min(ans,mid);r=mid-1;}
        else if(rnd(mid)<=0){r=mid-1;}
        else{
            l=mid+1;
        }
    }
    if(ans==10000000000000){return -1;}
    else return ans;
}
int main(){
    cin>>h>>n;
    for(int i=1;i<=n;i++){
        cin>>d[i];
        sum[i]=sum[i-1]+d[i];
    }
    cout<<rnd(8)<<endl;
    cout<<src();
}
