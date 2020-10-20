#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
void space(ll x){
    for(ll i=1;i<=x;i++){
        cout<<" ";
    }
}
void star(ll x){
    for(ll i=1;i<=x;i++){
        cout<<"*";
    }
    cout<<endl;
}
int main(){
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        space(n-i);star(i);
    }

}
