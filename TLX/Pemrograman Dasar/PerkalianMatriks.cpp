#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll a[101][101],b[101][101],c[101][101];
int main(){
    ll n,m,p;
    cin>>n>>m>>p;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(ll i=1;i<=m;i++){
        for(ll j=1;j<=p;j++){
            cin>>b[i][j];
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=p;j++){
            for(ll k=1;k<=m;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
            cout<<c[i][j];
            if(j<p){cout<<" ";}
        }
        cout<<endl;
    }
}


