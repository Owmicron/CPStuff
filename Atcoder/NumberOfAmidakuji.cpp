#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;
typedef map <str,int> mapsi;
typedef map <str,int> :: iterator mapsitr;
typedef set <int> :: iterator sitr;
typedef set <ll> :: iterator sltr;
#define mset multiset
typedef mset <int> msi;
typedef mset <ll> msll;
typedef mset <int> :: iterator msitr;
typedef mset <ll> :: iterator msltr;
#define mp make_pair
#define pb push_back
#define pob pop_back
#define fi first
#define se second
#define fs first.second
#define ss second.second
#define ff first.first
#define sf second.first
ll md = 1000000007;
int h,w,k,f;
ll memo[200][16];
bool calc[200][16],noline[10],line[10];
int depth[10];
bool isvalid(){
    bool vv=true;
    for(int i=1;i<w;i++){
        if(noline[i] && depth[i]==1){vv=false;break;}
        if(line[i] && depth[i]==0){vv=false;break;}
        if(i>1){
            if(depth[i]==1 && depth[i-1]==1){vv=false;break;}
        }
    }
    return vv;
}
ll permute (ll x){
    if(x < w-1){
        for(int i=0;i<=1;i++){
            depth[x]=i;
            permute(x+1);
        }
    }
    else if(x==w-1){
        for(int i=0;i<=1;i++){
            depth[x]=i;
            if(isvalid()){
                f++;
//                for(int j=1;j<w;j++){
//                    cout<<depth[j]<<" ";
//                }cout<<endl;
            }
        }

    }
}
ll straight (ll land){
    for(int i=0;i<=9;i++)noline[i]=false;
    for(int i=0;i<=9;i++)line[i]=false;

    f = 0;
    noline[land-1] = true;
    noline[land] = true;
    permute(1);
    return max(1,f);
}
ll left (ll land){
    for(int i=0;i<=9;i++)noline[i]=false;
    for(int i=0;i<=9;i++)line[i]=false;

    f = 0;
    line[land-1] = true;
    noline[land] = true;
    permute(1);
    return max(1,f);
}
ll right (ll land){
    for(int i=0;i<=9;i++)noline[i]=false;
    for(int i=0;i<=9;i++)line[i]=false;

    f = 0;
    noline[land-1] = true;
    line[land] = true;
    permute(1);
    return max(1,f);
}
ll dp (ll height, ll land){
    if(land < 1 || land > w){return 0;}
    else if(height == 0){
        if(land==1)return 1;
        else return 0;
    }
    else if(calc[height][land]){return memo[height][land];}
    else{
        ll ans=0;
        ll x,y,z,p;
        if(height>0){x=straight(land);}
        else{x=1;}
        p = ((dp(height-1,land)%md) * (x%md))%md;
        ans = ((ans%md) + (p%md))%md;

        if(height>0){y=left(land);}
        else{y=1;}
        p = ((dp(height-1,land-1)%md) * (y%md))%md;
        ans = ((ans%md) + (p%md))%md;

        if(height>0){z=right(land);}
        else{z=1;}
        p = ((dp(height-1,land+1)%md) * (z%md))%md;
        ans = ((ans%md) + (p%md))%md;
//        cout<<height<<" "<<land<<" "<<x<<" "<<y<<" "<<z<<endl;
        calc[height][land]=true;
        memo[height][land]=ans;
        return ans;
    }
}
int main(){
    cin>>h>>w>>k;
    cout<<dp(h,k)<<endl;
//    for(int i=1;i<h+1;i++){
//        for(int j=1;j<=w;j++){
//            cout<<i<<" "<<j<<" "<<dp(i,j)<<endl;
//        }
//    }
}
