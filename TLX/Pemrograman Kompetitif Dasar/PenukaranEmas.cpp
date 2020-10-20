#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string  str;
ll n,memo[2000];
bool vis[2000];
ll f(ll x){
    if(x<=1){return x;}
    else{
        if(vis[x]){
            return memo[x];
        }
        else{
            memo[x] = max(x , f(x/2)+f(x/3)+f(x/4));
            vis[x]=true;
            return memo[x];
        }
    }
}
int main(){
    cin>>n;
    cout<<f(n)<<endl;
}
