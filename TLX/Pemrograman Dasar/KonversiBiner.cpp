#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
void bin(ll x){
    if(x==1){cout<<x;}
    else{
        bin(x/2);
        if(x%2==0){cout<<0;}
        else{cout<<1;}

    }
}
int main(){
    ll n;
    cin>>n;
    bin(n);cout<<endl;
}


