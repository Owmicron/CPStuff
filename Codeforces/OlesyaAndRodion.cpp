#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,t;
int main(){
    cin>>n>>t;
    if(t<10){
        cout<<t;
        for(ll i=1;i<n;i++){cout<<0;}
    }
    else{
        if(n>1){cout<<t;
        for(ll i=1;i<n-1;i++){cout<<0;}}
        else{cout<<-1;}
    }
}
