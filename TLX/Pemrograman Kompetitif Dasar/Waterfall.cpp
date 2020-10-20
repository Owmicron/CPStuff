#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll v,h,n,v1[250100],t[250100],h1[250100],h2[250100],l[250100],r[250100];
pair<ll,ll> s[250100];
bool vis[501][501];
ll memo[501][501];
bool inrange(ll target,ll left,ll right){
    if((target>=left)&&(target<=right)){return true;}
    else{return false;}
}
ll f(ll x,ll y){
    ll ans=0;
    if((x<1)||(x>h)){return 0;}
    if(vis[x][y]){return memo[x][y];}
    else{
        for(ll i=1;i<=n;i++){
            if(y<t[i]){
                if(inrange(x,l[i],r[i])){
                    ans = 1;
                    ans+= f(l[i]-1,t[i]);
                    ans+= f(r[i]+1,t[i]);
                    break;
                }
            }
        }
        vis[x][y]=true;memo[x][y]=ans;
        return ans;
    }
}
int main(){
    cin>>v>>h>>n;
    for(ll i=1;i<=n;i++){
        cin>>v1[i]>>h1[i]>>t[i]>>h2[i];
        s[i].first=v1[i];s[i].second=i;
    }
    sort(s+1,s+1+n);
    for(ll i=1;i<=n;i++){
        l[i] = h1[s[i].second];
        r[i] = h2[s[i].second];
        t[i] = v1[s[i].second]-1;
        //cout<<l[i]<<" "<<r[i]<<" "<<t[i]<<endl;
    }
    ll mx = -1;
    for(ll i=1;i<=h;i++){
        mx = max(mx,f(i,-1));
        //cout<<f(i,0)<<endl;
    }
    cout<<mx<<endl;

}
