#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,m,k,ansx,ansy,p[101][101];
bool valid(ll y, ll x){
    if ((x>=1)&&(x<=m)&&(y>=1)&&(y<=n)){return true;}
    else{return false;}
}
ll v(ll y, ll x){
    ll a=1;
    if(valid(y-1,x)){a*=p[y-1][x];}
    if(valid(y,x-1)){a*=p[y][x-1];}
    if(valid(y,x+1)){a*=p[y][x+1];}
    if(valid(y+1,x)){a*=p[y+1][x];}
    return a;
}
int main(){
    cin>>n>>m>>k;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin>>p[i][j];
        }
    }
    ansx=1000;
    ansy=1000;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(v(i,j)==k){
                if(j<ansx){ansx=j;ansy=i;}
                else if(j==ansx){
                    if(i<ansy){ansx=j;ansy=i;}
                }
            }
        }
    }
    if(ansx==1000){ansx=0;ansy=0;}
    cout<<ansy<<" "<<ansx<<endl;
}
