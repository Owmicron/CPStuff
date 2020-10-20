#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,memo[100];
bool calc[100];
ll shake(ll x){
    if(!calc[x]){
        if(x==0){return 1;}
        else{
            ll l = x-2;
            ll r = 0;
            ll ans = 0;
            while(l>=0){
                ans += shake(l)*shake(r);
                l-=2;
                r+=2;
            }
            memo[x]=ans;
            calc[x]=true;
            return ans;
        }
    }
    else{
        return memo[x];
    }

}
int main(){
    cin>>n;
    cout<<shake(n)<<endl;
}
