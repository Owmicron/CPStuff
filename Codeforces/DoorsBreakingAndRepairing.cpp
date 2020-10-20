#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,x,y,d[101],a;
int main(){
    cin>>n>>x>>y;
    for(ll i=1;i<=n;i++){
        cin>>d[i];
        if(d[i] <= x){a++;}
    }
    if(x>y){cout<<n;}
    else{
        if(a%2==0)cout<<a/2;
        else{ cout<<a/2 + 1 ;}
    }
}
