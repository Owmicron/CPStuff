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
    if(num2==0)return 1%MOD;
    else if(num2==1)return num1%MOD;
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
int n,m;
map < pii , int > edges;
pii st,en,p[100010];
void ROW(){
    vector < pair < pii , int > > row;
    for(int i = 1; i <= m; ++i) row.pb(mp(mp(p[i].fi,p[i].se),i));
    sort(all(row));

    for(int i = 1; i < row.size(); ++i){
        int dist = row[i].ff - row[i-1].ff;
        int u = row[i-1].se;
        int v = row[i].se;
        if(u > v) swap(u,v);
        if(edges.count({u,v})) edges[{u,v}] = min(edges[{u,v}],dist);
        else edges[{u,v}] = dist;
    }
}
void COL(){
    vector < pair < pii , int > > row;
    for(int i = 1; i <= m; ++i) row.pb(mp(mp(p[i].se,p[i].fi),i));
    sort(all(row));

    for(int i = 1; i < row.size(); ++i){
        int dist = row[i].ff - row[i-1].ff;
        int u = row[i-1].se;
        int v = row[i].se;
        if(u > v) swap(u,v);
        if(edges.count({u,v})) edges[{u,v}] = min(edges[{u,v}],dist);
        else edges[{u,v}] = dist;
    }
}
ll dist[100010],INF = 1e15;
bool vis[100010];
vpii adj[100010];
void dijkstra(int x){
    for(int i = 1; i <= m; ++i) dist[i] = INF;
    dist[x] = 0;
    priority_queue < pii > q;
    q.push({0,x});

    while(!q.empty()){
        int node = q.top().se;
        q.pop();
        if(!vis[node]){
            vis[node] = true;
            for(auto u : adj[node]){
                int W = u.se;
                int v = u.fi;
                if(dist[v] > dist[node] + W){
                    dist[v] = dist[node] + W;
                    q.push({-dist[v],v});
                }
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

    cin >> n >> m;
    cin >> st.fi >> st.se >> en.fi >> en.se;
    for(int i = 1; i <= m; ++i){
        cin >> p[i].fi >> p[i].se;
    }

    p[++m] = st;
    ROW(); COL();

    for(auto i : edges){
        pii P = i.fi;
        int dd = i.se;

        adj[P.fi].pb({P.se,dd});
        adj[P.se].pb({P.fi,dd});
    }

    dijkstra(m);
    ll ans = 1e18;
    for(int i = 1; i <= m; ++i){
        ll d = abs(en.fi - p[i].fi) + abs(en.se - p[i].se);
        d += dist[i];
        ans = min(ans,d);
    }

    cout << ans << newl;
//    int sourc = 0;
//    int mx = INT_MAX;
//    for(int i = 1; i <= m; ++i){
//        int dist = min (abs(st.fi-p[i].fi) , abs(st.se-p[i].se) );
//        if(dist < mx) sourc = mx, mx = dist;
//    }

    return 0;
}
