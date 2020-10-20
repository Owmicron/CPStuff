#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll d,n,b,h,ans;
pair<ll,ll>choco [200000];
int main(){
    cin>>n>>d;
    for(ll i=1;i<=n;i++){
        cin>>h>>b;
        choco[i].first=h;
        choco[i].second=b;
    }
    sort(choco+1,choco+n+1);
    for(ll i=1;i<=n;i++){
        if((d/choco[i].first)>choco[i].second){
            d-=choco[i].first*choco[i].second;
            ans+=choco[i].second;
        }
        else{
            ans+=d/choco[i].first;
            break;
        }
    }
    cout<<ans<<endl;
}
