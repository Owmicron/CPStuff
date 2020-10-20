#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//turn on extra precision
//#pragma GCC target("fpmath=387")

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef string str;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;

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
#define rall(x) x.rbegin(),x.rend()
#define watch(x) cout << (#x) << " is : " << (x) << newl

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
vi dirx = {0,0,1,-1};
vi diry = {1,-1,0,0};
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
    if(97 <= int(x) && int(x) <= 122) return int(x-96);
    if(65 <= int(x) && int(x) <= 90) return int(x-64);
    return -1;
}
bool isect (int l1, int r1, int l2, int r2){
    pii p1 = {l1,r1};
    pii p2 = {l2,r2};
    if(p1>p2)swap(p1,p2);
    return (p2.fi <= p1.se);
}
ll quickpow (ll num1, ll num2, ll MOD){
    if(num2==0) return 1%MOD;
    else if(num2==1) return num1%MOD;
    else{
        ll temp = quickpow (num1,num2>>1LL,MOD); ll res = ((temp%MOD) * (temp%MOD))%MOD;
        if(num2&1) res = ((res%MOD)*(num1%MOD))%MOD; return res;
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

int h,w,k,INF = 1e8;
vector < vi > dist;
vector < vpii > up,down,lef,righ;
vector < vector <bool> > forbidden, vis;
pii st,en;

bool in_grid(pii p){
    int r = p.fi , c = p.se;
    return (0 <= r && r < h && 0 <= c && c < w);
}
bool visitable(int r, int c){
    return (in_grid({r,c}) && !forbidden[r][c]);
}
void delete_grid(int r, int c){
    if(in_grid(lef[r][c])) righ[lef[r][c].fi][lef[r][c].se] = righ[r][c];
    if(in_grid(righ[r][c])) lef[righ[r][c].fi][righ[r][c].se] = lef[r][c];
    if(in_grid(up[r][c])) down[up[r][c].fi][up[r][c].se] = down[r][c];
    if(in_grid(down[r][c])) up[down[r][c].fi][down[r][c].se] = up[r][c];
}
int man(pii a, pii b){
    return abs(a.fi - b.fi) + abs(a.se - b.se);
}
void bfs(){
    queue < pair < int , pii > > q;
    q.push({0,st});

    vis[st.fi][st.se] = true;
    while(!q.empty()){
        int r = q.front().sf;
        int c = q.front().ss;
        int d = q.front().fi;
        q.pop();
        dist[r][c] = d;
        pii cord;
        vpii v;

        // go up
        v.clear();
        v.pb({r,c});
        cord = up[r][c];
        while(visitable(cord.fi,cord.se) && man(cord,{r,c}) <= k){
            if(!vis[cord.fi][cord.se]){
                vis[cord.fi][cord.se] = true;
                v.pb(cord);
                q.push({d+1,cord});
            }
            cord = up[cord.fi][cord.se];
        }
        for(auto i : v) up[i.fi][i.se] = cord;

        // go down
        v.clear();
        v.pb({r,c});
        cord = down[r][c];
        while(visitable(cord.fi,cord.se) && man(cord,{r,c}) <= k){
            if(!vis[cord.fi][cord.se]){
                vis[cord.fi][cord.se] = true;
                v.pb(cord);
                q.push({d+1,cord});
            }
            cord = down[cord.fi][cord.se];
        }
        for(auto i : v) down[i.fi][i.se] = cord;

        // go left
        v.clear();
        v.pb({r,c});
        cord = lef[r][c];
        while(visitable(cord.fi,cord.se) && man(cord,{r,c}) <= k){
            if(!vis[cord.fi][cord.se]){
                vis[cord.fi][cord.se] = true;
                v.pb(cord);
                q.push({d+1,cord});
            }
            cord = lef[cord.fi][cord.se];
        }
        for(auto i : v) lef[i.fi][i.se] = cord;

        // go right
        v.clear();
        v.pb({r,c});
        cord = righ[r][c];
        while(visitable(cord.fi,cord.se) && man(cord,{r,c}) <= k){
            if(!vis[cord.fi][cord.se]){
                vis[cord.fi][cord.se] = true;
                v.pb(cord);
                q.push({d+1,cord});
            }
            cord = righ[cord.fi][cord.se];
        }
        for(auto i : v) righ[i.fi][i.se] = cord;

    }
    return;
}

int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> h >> w >> k;
    for(int i = 0; i < h; ++i){
        vi v; vector <bool> q;
        vpii UP,DOWN,LEF,RIGH;
        for(int j = 0; j < w; ++j) {
            v.pb(INF);
            q.pb(false);
            UP.pb({i-1,j});
            DOWN.pb({i+1,j});
            LEF.pb({i,j-1});
            RIGH.pb({i,j+1});
        }
        up.pb(UP);
        down.pb(DOWN);
        lef.pb(LEF);
        righ.pb(RIGH);
        dist.pb(v);
        vis.pb(q);
        forbidden.pb(q);
    }

    cin >> st.fi >> st.se >> en.fi >> en.se;
    --st.fi, --st.se, --en.fi, --en.se;

    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            char c; cin >> c;
            if(c == '@') forbidden[i][j] = true;
        }
    }

    bfs();
//    for(auto i : dist){
//        for(auto j : i) cout << j << " ";
//        cout << newl;
//    }

    if(dist[en.fi][en.se] == INF) dist[en.fi][en.se] = -1;
    cout << dist[en.fi][en.se] << newl;

    return 0;
}
