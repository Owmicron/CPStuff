#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p5[201];
int main(){
    int t;
    cin>>t;
    for(ll i=1;i<=200;i++){
        p5[i]=i*i*i*i*i;
    }

    ll b[6];
    ll c=1,p=1;
    for(ll i=1;i<=5;i++){b[i]=1;}
    for(ll i=1;i<=5;i++){
        for(ll j=1;j<=5;j++){
            cout<<b[i]<<" ";
        }cout<<endl;

    }
}

