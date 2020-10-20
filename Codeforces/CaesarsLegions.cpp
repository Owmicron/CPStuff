#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n1,n2,k1,k2;
ll md = 100000000;
bool calc[210][110][110][3];
ll memo[210][110][110][3];
ll dp (ll x, ll f, ll h, ll cur) {
    if(f<0 || x>n1+n2 || h<0) return 0;
    else if(calc[x][f][h][cur])return memo[x][f][h][cur];
    else{
        if(x==n1+n2) return 1;
        ll ans=0;
        calc[x][f][h][cur]=true;
        if(cur==0 || x==0){
            for(int i=1;i<=k1;i++){
                ans += dp(x+i,f-i,h,1)%md;
            }
            for(int i=1;i<=k2;i++){
                ans += dp(x+i,f,h-i,2)%md;
            }
        }
        else if(cur==1){
            for(int i=1;i<=k2;i++){
                ans+=dp(x+i,f,h-i,2)%md;
            }
        }
        else{
            for(int i=1;i<=k1;i++){
                ans+=dp(x+i,f-i,h,1)%md;
            }
        }
        ans%=md;
        memo[x][f][h][cur]=ans;
        return ans;
    }
}

int main(){
    scanf("%d %d %d %d",&n1,&n2,&k1,&k2);
    cout<<dp(0,n1,n2,0);
}
