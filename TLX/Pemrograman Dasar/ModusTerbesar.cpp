#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll a[100000];
ll f[1001];
int main(){
    ll n;cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        f[a[i]]++;
    }
    ll fm,m;
    fm=-1;m=-1;
    for(ll i=1;i<=1001;i++){
        if(f[i]>fm){fm=f[i];m=i;}
        if(f[i]==fm){
            if(i>m){m=i;}
        }
    }
    cout<<m<<endl;
}

