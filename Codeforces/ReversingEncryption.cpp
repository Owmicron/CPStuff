#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str s;
str rev(ll x){
    str t = "";
    for(ll i=x-1;i>=0;i--){
        t+= s[i];
    }
    for(ll i=x;i<=s.size()-1;i++){
        t+= s[i];
    }
    return t;
}
int main(){
    ll n;
    cin>>n;
    cin>>s;
    for(ll i=1;i<=n;i++){
        if(n%i==0){s=rev(i);}
    }
    cout<<s<<endl;
}


