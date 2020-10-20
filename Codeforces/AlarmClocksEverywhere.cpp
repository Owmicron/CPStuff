#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,m;
ll x[400000],p[400000],g,ans;
vector<ll> sel;
ll gcd (ll a, ll b){
    ll awal,bwal;
    if(a<b)swap(a,b);
    awal=a;bwal=b;
    ll c=a%b;
    while(c!=0){
        a = b;
        b = c;
        c = a%b;
    }
    return b;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&x[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%lld",&p[i]);
    }
    for(int i=2;i<=n;i++){
        sel.push_back(x[i]-x[i-1]);
    }
    if(n==2){
        g = sel[0];
    }
    else{
        g = gcd(sel[0],sel[1]);
        for(int i=2;i<sel.size();i++){
            g = gcd (g,sel[i]);
        }
    }
    ans=-1;
    for(int i=1;i<=m;i++){
        if(g%p[i]==0){ans=i;break;}
    }
    if(ans!=-1){
        printf("YES\n");
        printf("%lld %lld\n",x[1],ans);
    }
    else{
        printf("NO\n");
    }

}

