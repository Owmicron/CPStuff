#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,a[4],memo[5000];
bool calc[5000];
ll solve(ll x){
    //cout<<x<<endl;
    if(x==0){return 0;}
    if(calc[x]){return memo[x];}
    else{
        ll best = -1000;
        for(ll i=1;i<=3;i++){
            if(a[i]<=x){
            best = max(best, solve(x-a[i])+1 );
            }
        }
        memo[x]=best;
        calc[x]=true;
        return best;
    }
}
int main(){
    cin>>n>>a[1]>>a[2]>>a[3];
    cout<<solve(n);

}
