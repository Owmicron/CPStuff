#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//turn on excess precision
//#pragma GCC target("fpmath=387")

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
#define rall(x) x.rbegin(),x.rend()
#define watch(x) cout << (#x) << " is : " << (x) << newl

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
ll n,m,dist[100010],p[100010],h[100010],num[100010];
ll gud[100010],bat[100010],mx;
vll adj[100010];
bool vis[100010];
vi v[100010];
void bfsd(){
    for(int i=1;i<=n;++i) vis[i]=false, dist[i] = 0, gud[i] = 0;
    queue <pii> q;
    q.push({1,0});
    mx = 0;
    while(!q.empty()){
        int node = q.front().fi;
        int d = q.front().se;
        q.pop();
        if(!vis[node]){
            vis[node] = true;
            dist[node] = d;
            mx = max(mx,(ll)d);
            v[d].pb(node);
            for(auto i : adj[node]) q.push({i,d+1});
        }
    }
}
void bfs(){
    for(int i=1;i<=n;++i) num[i] = 0;
    for(int i = mx; i >= 0; --i){
        for(auto j : v[i]){

            num[j] += p[j];
            for(auto k : adj[j]){
                if(dist[k] < i) num[k] += num[j];
            }
        }
    }
    mx = 0;
//    for(int i=1;i<=n;++i){
//        cout<<i<<" : "<<num[i]<<newl;
//    }
}
int findprev(int x){
    if(x == 1) return 0 ;
    for(auto i : adj[x]) if(dist[i] < dist[x]) return i;
}
bool solve(){
    for(int i=1;i<=n;++i) vis[i]=false;
    queue <int> q;
    q.push(1);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        if(!vis[node]){
            vis[node] = true;
            ll gp = m;
            if(node > 1) gp = gud[findprev(node)];
            ll x = num[node];
            ll y = h[node];
            ll temp = x - y;
            if(temp < 0 || temp % 2) return false;
            temp/=2;
            ll bed = temp;
            ll g = x - bed;

            if(g < 0) return false;
            if(g > gp) return false;

            gud[node] = g;
            bat[node] = bed;

            if(node > 1) gud[findprev(node)] -= g;

            for(auto i : adj[node]) {
                if(dist[i] > dist[node]) q.push(i);
            }

        }
    }

    return true;
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i <= n; ++i) adj[i].clear(), v[i].clear();
        for(int i = 1; i <= n; ++i) cin >> p[i];
        for(int i = 1; i <= n; ++i) cin >> h[i];

        for(int i = 1; i < n; ++i){
            int u, v; cin >> u >> v;
            adj[u].pb(v); adj[v].pb(u);
        }
        bfsd();
        bfs();

        cout<<(solve() ? "YES\n" : "NO\n");

    }

    return 0;
}
