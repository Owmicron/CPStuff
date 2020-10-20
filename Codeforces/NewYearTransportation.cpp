#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,t,a[100000];
bool visit[100000];
int main(){
    cin>>n>>t;
    for(ll i=1;i<n;i++){cin>>a[i];}
    ll pos=1;
    while(pos<n){
        visit[pos]=true;
        pos+=a[pos];
    }
    visit[pos]=true;

    if(visit[t]){cout<<"YES";}
    else{cout<<"NO";}

}
