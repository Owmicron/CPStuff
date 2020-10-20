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

vi leave[200010],to[200010],und[200010];
int color[200010],n,m;
bool vis[200010];
bool cyc = false;
set <pii> edges;
void dfs(int from, int node){
    if(color[node] == 0){
        color[node] = 1;
        for(auto i : leave[node]) if(i != from) dfs(node,i);
        color[node] = 2;
    }
    else if(color[node] == 1){
        cyc = true;
    }
}
vpii pending;
void topo(int node){
    if(!vis[node]){
        vis[node] = true;
        for(auto i : leave[node]) topo(i);
        for(auto i : und[node]){
            int u = min(node,i);
            int v = max(node,i);
            if(edges.count({u,v})){
                edges.erase({u,v});
                pending.pb({i,node});
            }
        }
        for(auto i : to[node]) topo(i);
    }
}
bool has_cycle(){
    cyc = false;
    for(int i=1;i<=n;++i) {dfs(i,i); if(cyc) return cyc;}
    return false;
}
void solve(){
    for(int i=1;i<=n;++i) {
        pending.clear();
        topo(i);
        for(auto j : pending) leave[j.fi].pb(j.se), to[j.se].pb(j.fi);
    }
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;
    while(t--){
        edges.clear();
        cin>>n>>m;
        for(int i=1;i<=n;++i) leave[i].clear(), to[i].clear(), und[i].clear(), color[i] = 0, vis[i] = false;
        for(int i=1;i<=m;++i){
            int typ, u, v; cin>>typ>>u>>v;
            if(typ == 0) und[u].pb(v), und[v].pb(u), edges.insert({min(u,v),max(u,v)});
            else{
                leave[u].pb(v);
                to[v].pb(u);
            }
        }

        if(has_cycle()) cout<<"NO\n";
        else{
            cout<<"YES\n";
            solve();
            vpii v;
            for(int i=1;i<=n;++i){
                for(auto j : leave[i]) v.pb({i,j});
            }
            for(int i=1;i<=n;++i) color[i] = 0;

            for(auto i : v) cout<<i.fi<<" "<<i.se<<newl;

        }
    }
    return 0;

}
