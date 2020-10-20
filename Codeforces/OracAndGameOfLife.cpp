#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
using namespace __gnu_pbds;

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
typedef map <int , int> mint;
typedef map <ll , ll> mll;
typedef set <int> si;
typedef set <ll> sll;
typedef si :: iterator sitr;
typedef si :: reverse_iterator rsitr;
typedef sll :: iterator sltr;
typedef sll :: reverse_iterator rsltr;
#define mset multiset

typedef mset <int> msi;
typedef mset <ll> msll;
typedef msi :: iterator msitr;
typedef msi :: reverse_iterator msritr;
typedef msll :: iterator msltr;
typedef msll :: reverse_iterator mslritr;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define fs first.second
#define ss second.second
#define ff first.first
#define sf second.first
#define newl '\n'
#define fbo find_by_order
#define ook order_of_key
#define all(x) x.begin(), x.end()
#define watch(x) cout << (#x) << " is : " << (x) << newl

char to_upper (char x){
    if( 97 <= int(x) && int(x) <= 122) return char(x-32);
    if( 65 <= int(x) && int(x) <= 90) return x;
    return -1;
}
char to_lower (char x){
    if( 97 <= int(x) && int(x) <= 122) return x;
    if( 65 <= int(x) && int(x) <= 90) return char(x+32);
    return -1;
}
int numerize (char x){
    if(48 <= int(x) && int(x) <= 57) return int(x-'0');
    if( 97 <= int(x) && int(x) <= 122) return int(x-96);
    if( 65 <= int(x) && int(x) <= 90) return int(x-64);
    return -1;
}
bool isect (int l1, int r1, int l2, int r2){
    pii p1,p2;
    p1 = mp(l1,r1); p2 = mp(l2,r2);
    if(p1>p2)swap(p1,p2);
    if(p2.fi <= p1.se)return true;
    else return false;
}
ll quickpow (ll num1, ll num2, ll MOD){
    if(num2==0)return 1%MOD;
    else if(num2==1)return num1%MOD;
    else{
        ll temp = quickpow (num1,num2/2,MOD); ll res = ((temp%MOD) * (temp%MOD))%MOD;
        if(num2%2==1) res = ((res%MOD)*(num1%MOD))%MOD; return res;
    }
}
ll invmod (ll num, ll MOD){return quickpow (num,MOD-2,MOD);}
ll gcd (ll num1, ll num2){
    if(num1 < num2) swap(num1,num2); ll num3 = num1 % num2 ;
    while(num3 > 0){ num1 = num2; num2 = num3; num3 = num1 % num2;}
    return num2;
}
ll lcm (ll num1 , ll num2){return (ll) (num1/__gcd(num1,num2))*num2;}
// end of Template
int n,m,t,gud[1010][1010];
char grid[1010][1010];
bool good[1010][1010];
bool vis[1010][1010];
pii par[1010][1010];
vpii gudgrid;
bool ingrid(int r, int c){
    return (1<=r && r<=n && 1<=c && c<=m);
}
pii getpar(pii x){
    int r = x.fi;
    int c = x.se;
    return (par[r][c] == mp(r,c) ? mp(r,c) : par[r][c] = getpar(par[r][c]));
}
void join (pii a, pii b){
    pii repa = getpar(a);
    pii repb = getpar(b);
    if(repb != repa) par[repb.fi][repb.se] = repa;
}
void decide(int r, int c){
    int f = 0;
    if(ingrid(r+1,c) && grid[r+1][c] == grid[r][c]) ++f;
    if(ingrid(r-1,c) && grid[r-1][c] == grid[r][c]) ++f;
    if(ingrid(r,c+1) && grid[r][c+1] == grid[r][c]) ++f;
    if(ingrid(r,c-1) && grid[r][c-1] == grid[r][c]) ++f;

    if(!f) vis[r][c] = true, good[r][c] = false;
    else{
        queue <pii> q;
        q.push(mp(r,c));

        while(!q.empty()){
            r = q.front().fi;
            c = q.front().se;
            q.pop();
            if(!vis[r][c]){
                good[r][c] = true;
                gudgrid.pb(mp(r,c));
                gud[r][c] = 0;
                vis[r][c] = true;
                if(ingrid(r+1,c) && grid[r+1][c] == grid[r][c]) q.push(mp(r+1,c)), join(mp(r,c),mp(r+1,c));
                if(ingrid(r-1,c) && grid[r-1][c] == grid[r][c]) q.push(mp(r-1,c)), join(mp(r,c),mp(r-1,c));
                if(ingrid(r,c+1) && grid[r][c+1] == grid[r][c]) q.push(mp(r,c+1)), join(mp(r,c),mp(r,c+1));
                if(ingrid(r,c-1) && grid[r][c-1] == grid[r][c]) q.push(mp(r,c-1)), join(mp(r,c),mp(r,c-1));
            }
        }
    }
}
void solve(){
    queue < pair <pii,int> > q;
    while(!gudgrid.empty()){
        q.push(mp(gudgrid.back(),0));
        gudgrid.pob();
    }
    while(!q.empty()){
        int r = q.front().ff;
        int c = q.front().fs;
        int itr = q.front().se;
        q.pop();
        if(!vis[r][c]){
            vis[r][c] = true;
            if(ingrid(r+1,c) && !good[r+1][c]){
                good[r+1][c] = true;
                gud[r+1][c] = itr+1;
                join(mp(r,c),mp(r+1,c));
                q.push({mp(r+1,c),itr+1});
            }
            if(ingrid(r-1,c) && !good[r-1][c]){
                good[r-1][c] = true;
                gud[r-1][c] = itr+1;
                join(mp(r,c),mp(r-1,c));
                q.push({mp(r-1,c),itr+1});
            }
            if(ingrid(r,c+1) && !good[r][c+1]){
                good[r][c+1] = true;
                gud[r][c+1] = itr+1;
                join(mp(r,c),mp(r,c+1));
                q.push({mp(r,c+1),itr+1});
            }
            if(ingrid(r,c-1) && !good[r][c-1]){
                good[r][c-1] = true;
                gud[r][c-1] = itr+1;
                join(mp(r,c),mp(r,c-1));
                q.push({mp(r,c-1),itr+1});
            }
        }

    }
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m>>t;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>grid[i][j], par[i][j] = mp(i,j);

    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(!vis[i][j]) decide(i,j);

    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            vis[i][j] = false;

//    cout<<newl;
//    for(int i=1;i<=n;++i){
//        for(int j=1;j<=m;++j){
//            pii x = getpar(mp(i,j));
//            cout<<"("<<x.fi<<","<<x.se<<") ";
//        }cout<<newl;
//    }

    solve();

//    cout<<newl;
//    for(int i=1;i<=n;++i){
//        for(int j=1;j<=m;++j){
//            pii x = getpar(mp(i,j));
//            cout<<"("<<x.fi<<","<<x.se<<") ";
//        }cout<<newl;
//    }
//
//    for(int i=1;i<=n;++i){
//        for(int j=1;j<=m;++j){
//            cout<<good[i][j];
//        }cout<<newl;
//    }
    while(t--){
        int r,c; ll p;cin>>r>>c>>p;
        if(!good[r][c]) cout<<grid[r][c]<<newl;
        else if(p<=gud[r][c]) cout<<grid[r][c]<<newl;
        else{
            pii x = getpar(mp(r,c));
            int d = numerize(grid[x.fi][x.se]);
            if((ll)p%2==0) cout<<d<<newl;
            else cout<<1-d<<newl;
        }
    }

    return 0;
}
