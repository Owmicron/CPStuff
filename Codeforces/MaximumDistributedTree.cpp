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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
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
int n,m,k,depth[100010];
vi adj[100010];
vll prime;
bool vis[100010];
bool calc[100010];
ll child[100010];
ll md = 1e9 + 7;
void precdepth(){
    for(int i = 1; i <= n; ++i) vis[i] = false;
    queue <pii> q; q.push({1,1});

    while(!q.empty()){
        int node = q.front().fi;
        int d = q.front().se;
        q.pop();
        if(!vis[node]){
            vis[node] = true;
            depth[node] = d;
            for(auto i : adj[node]){
                q.push({i,d+1});
            }
        }
    }
}
ll getchild(int node){
    if(calc[node]) return child[node];
    calc[node] = true;
    ll &res = child[node];
    res = 1;
    for(auto i : adj[node]){
        if(depth[i] > depth[node]) res += getchild(i);
    }
    return res;
}
ll solve(){
    for(int i = 1; i <= n; ++i) calc[i] = false;
    precdepth();
    for(int i = 1; i <= n; ++i) vis[i] = false;
    queue <int> q;
    q.push(1);

    vll v;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(!vis[node]){
            vis[node] = true;
            for(auto i : adj[node]){
                if(depth[i] > depth[node]){
                    ll A = getchild(1) - getchild(i);
                    ll B = getchild(i);
                    ll res = A * B;
                    v.pb(res);

                    q.push(i);
                }
            }
        }
    }

    sort(all(v));
    ll res = 0;

    if((int)prime.size() <= (int) v.size()){
        for(int i = v.size()-1; i >= 0; --i){
            ll f;
            if(prime.empty()) f = 1;
            else {f=prime.back(); prime.pob();}

            ll temp = ((f%md) * (v[i]%md)) % md;
            res = (res + temp) % md;
        }
    }
    else{
        reverse(all(prime));
        for(int i = 0; i < v.size(); ++i){
            ll f;
            if(i == v.size()-1){
                f = 1;
                while(!prime.empty()){
                    f = (f * prime.back() % md) % md;
                    prime.pob();
                }
            }
            else {
                f = prime.back();
                f %= md;
                prime.pob();
            }
            ll temp = ((f%md)*(v[i]%md)) % md;
            res = (res + temp) % md;
        }
    }
    return res;
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        prime.clear();
        cin >> n;
        for(int i = 1; i <= n; ++i) adj[i].clear();
        for(int i = 1; i < n; ++i){
            int u,v; cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        cin >> m;
        for(int i = 0; i < m; ++i){
            int temp; cin >> temp;
            prime.pb(temp);
        }
        sort(all(prime));
        cout << solve() << newl;
    }
    return 0;
}
