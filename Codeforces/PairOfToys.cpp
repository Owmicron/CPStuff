#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,k,a,b,c,d;
ll inter(ll a,ll b,ll c,ll d){
    if(c>d){return 0;}
    if(a>b){return 0;}
    if(c>b){return 0;}
    else if(c==b){return 1;}
    else{
        ll ans = b-c+1;
        if(d<b){ans -= (b-d) ;}
        return ans;
    }
}
ll l1,l2,r1,r2;
int main(){
    cin>>n>>k;
    l1 = 1;
    r1 = n;
    l2 = k/2+1;
    r2 = k-1;
    cout<<inter(l1,r1,l2,r2);


}
