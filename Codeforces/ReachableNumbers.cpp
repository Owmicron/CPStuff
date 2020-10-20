#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n;
ll start,ans;
map <str,bool> m;
ll f (ll x){
    x++;
    while(x%10==0)x/=10;
    return x;
}
str s (ll x){
    str ss="";
    while(x>0){
        int d = x%10;
        ss += char(d+48);
        x/=10;
    }
    return ss;
}
int main(){
    cin>>n;
    str z = s(n);

    while(!m[z]){
        m[z]=true;
        ans++;
        n = f(n);
        z = s(n);
    }
    cout<<ans;
}
