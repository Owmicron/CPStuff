#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll a,b,k,x;
ll f(ll z, ll t){
    if(t==1){return abs(a*z+b);}
    else{return abs(a*f(z,t-1)+b);}
}
int main(){
    cin>>a>>b>>k>>x;
    cout<<f(x,k)<<endl;
}
