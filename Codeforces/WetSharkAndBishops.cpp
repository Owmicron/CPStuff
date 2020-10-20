#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
bool grid[1001][1001];
ll n,x,y,ans;

ll checkr(ll a,ll b){
    ll v=0;
    for(ll i=0;i<=1000;i++){
        if((a+i > 1000)||(b+i >1000)){break;}
        if(grid[a+i][b+i]){v++;}
    }
    return v;
}

ll checkl(ll a,ll b){
    ll v=0;
    for(ll i=0;i<=1000;i++){
        if((a-i < 1)||(b+i >1000)){break;}
        if(grid[a-i][b+i]){v++;}

    }
    return v;
}

ll cnt(ll x){
    return ((x*(x-1))/2);
}

int main(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>x>>y;
        grid[x][y]=true;
    }
    for(ll i=1;i<=1000;i++){
        ll num = checkr(i,1);
        ans+=cnt(num);
        //if(num>0){cout<<i<<" "<<1<<" "<<num<<endl;}
    }
    for(ll i=2;i<=1000;i++){
        ll num = checkr(1,i);
        ans+=cnt(num);
        //if(num>0){cout<<1<<" "<<i<<" "<<num<<endl;}
    }
    for(ll i=1;i<=1000;i++){
        ll num = checkl(i,1);
        ans+=cnt(num);
        //if(num>0){cout<<i<<" "<<1<<" "<<num<<endl;}
    }
    for(ll i=2;i<=1000;i++){
        ll num = checkl(1000,i);
        ans+=cnt(num);
        //if(num>0){cout<<1000<<" "<<i<<" "<<num<<endl;}
    }
    cout<<ans<<endl;
}




