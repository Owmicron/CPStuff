#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int main(){
    ll n,k;
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        if(i%k==0){cout<<"*";}
        else{cout<<i;}

        if(i<n){cout<<" ";}
        else{cout<<endl;}

    }

}
