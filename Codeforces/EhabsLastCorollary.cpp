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
int n,m,k;
vi adj[100010];
void solve_tree(){
    bool vis[n+2];
    for(int i=1;i<=n;++i) vis[i] = false;
    queue <pii> q;
    q.push({1,0});

    vi a,b;
    while(!q.empty()){
        int node = q.front().fi;
        int dist = q.front().se;
        q.pop();
        if(!vis[node]){
            vis[node] = true;
            if(dist % 2) a.pb(node);
            else b.pb(node);
            for(auto i : adj[node]){
                q.push({i,dist+1});
            }
        }
    }

    if(a.size() < b.size()) swap(a,b);

    int req = k/2 + (k%2);

    cout<<1<<newl;
    for(int i=0;i<req;++i) cout<<a[i]<<" ";cout<<newl;
}
int color[100010];
vi temp;
deque <int> cycle;
bool found = false;
void dfs(int node, int pre){
    if(color[node] == 0){
        color[node] = 1;
        temp.pb(node);
        for(auto i : adj[node]){
            if(i != pre) dfs(i,node);
            if(found) break;
        }
        if(!found) temp.pob();
    }
    else{
        found = true;
        cycle.pb(node);
        while(temp.back() != node){
            cycle.pb(temp.back());
            temp.pob();
        }
    }
}
bool incycle[100010];
set <pii> edges;
void solve_cyclic(){
    dfs(1,1);

    for(auto i : cycle) incycle[i] = true;
    for(int i=1;i<cycle.size();++i){
        int u = cycle[i-1];
        int v = cycle[i];
        if(u > v) swap(u,v);
        edges.erase({u,v});
    }
    int u = cycle.back();
    int v = cycle[0];
    if(u > v) swap(u,v);
    edges.erase({u,v});

    for(auto p : edges){
        if(!(incycle[p.fi] && incycle[p.se])) continue;
        while(!( cycle.front() == p.fi || cycle.front() == p.se )) {
            incycle[cycle.front()] = false;
            cycle.pof();
        }
        while(!( cycle.back() == p.fi || cycle.back() == p.se )) {
            incycle[cycle.back()] = false;
            cycle.pob();
        }
    }

    if(cycle.size() <= k){
        cout<<2<<newl;
        cout<<cycle.size()<<newl;
        for(auto i : cycle) cout<<i<<" ";cout<<newl;
    }
    else{
        int req = k/2 + (k%2);
        cout<<1<<newl;
        int idx = 0;
        for(int i=0;i<cycle.size();i+=2){
            ++idx;
            cout<<cycle[i]<<" ";
            if(idx == req) break;
        }cout<<newl;
    }
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m>>k;
    for(int i=0;i<m;++i){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
        if(u > v) swap(u,v);
        edges.insert({u,v});
    }

    if(m < n) solve_tree();
    else solve_cyclic();

    return 0;
}
