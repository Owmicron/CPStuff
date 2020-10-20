#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll f(ll x){
    if(x==1){
        return 1;
    }
    else{
        if(x%2==1){return (x*f(x-1));}
        else{return ((x/2)*f(x-1));}
    }
}
int main(){
    ll n;
    cin>>n;
    cout<<f(n)<<endl;

}
