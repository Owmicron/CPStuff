#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,b,h[30000],ans;
int main(){
    cin>>n>>b;
    for(ll i=1;i<=n;i++){cin>>h[i];}
    sort(h+1,h+1+n);
    for(ll i=n;i>=1;i--){
        ans+=h[i];
        if(ans>=b){cout<<n-i+1<<endl;break;}
    }
}
