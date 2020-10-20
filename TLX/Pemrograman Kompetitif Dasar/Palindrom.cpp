#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,x,memo [52][52][52];
str s;
bool vis[52][52][52];
ll lps(ll l, ll r){
    if(!vis[x][l][r]){
        ll ans;
        if(l==r){ans=1;}
        else if(r-l == 1){
            if(s[l]!=s[r]){ans=1;}
            else{ans=2;}
        }
        else{
            if(s[l]!=s[r]){
                ans = max(lps(l,r-1),lps(l+1,r));
            }
            else{
                ans = 2 + lps(l+1,r-1);
            }
        }
        vis[x][l][r]=true;
        memo[x][l][r]=ans;
        return ans;
    }
    else{
        return memo[x][l][r];
    }
}
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>s;
        x=i;cout<<lps(0,s.size()-1)<<endl;
    }
}
