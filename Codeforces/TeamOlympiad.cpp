#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,m;
vector<ll>pro,math,pe;
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        ll t;cin>>t;
        if(t==1){pro.push_back(i);}
        if(t==2){math.push_back(i);}
        if(t==3){pe.push_back(i);}
    }
    m=min(pro.size(),math.size());
    ll x=pe.size();
    m=min(m,x);
    cout<<m<<endl;
    for(ll i=1;i<=m;i++){
        cout<<pro.back()<<" "<<math.back()<<" "<<pe.back()<<endl;
        pro.pop_back();math.pop_back();pe.pop_back();
    }
}
