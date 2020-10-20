#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int main(){
    ll n;
    cin>>n;
    for(ll i=n;i>=1;i--){
        if(n%i==0){cout<<i<<endl;}
    }
}
