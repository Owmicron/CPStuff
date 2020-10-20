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
ll n,m;
vi adj[100010];
bool is_bipartite(){
    int color[100010];
    bool vis[100010];
    for(int i=1;i<=n;++i) color[i] = -1, vis[i] = false;

    for(int i=1;i<=n;++i){
        if(!vis[i]){
            queue <pii> q;
            q.push({i,0});

            while(!q.empty()){
                int node = q.front().fi;
                int c = q.front().se;
                q.pop();
                if(!vis[node]){
                    vis[node] = true;
                    color[node] = c;
                    for(auto a : adj[node]){
                        if(vis[a] == false && color[a] == c) return false;
                        color[a] = 1-c;
                        q.push({a,color[a]});
                    }
                }
            }
        }
    }

    return true;
}
void solve_1(){
    bool vis[100010];
    for(int i=1;i<=n;++i) vis[i] = false;

    ll f[3];
    f[1] = f[2] = 0;
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            int comp = 0;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                if(!vis[node]){
                    vis[node] = true;
                    for(auto j : adj[node]) q.push(j);
                    comp++;
                }
            }
            f[comp]++;
        }
    }
    ll ans = f[2] * f[1];
    ans += (f[2] * (f[2]-1)) * 2;
    cout<<2<<" "<<ans<<newl;
}
void solve_2(){
    bool vis[100010];
    for(int i=1;i<=n;++i) vis[i] = false;
    ll ans = 0;
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            ll f[2];
            f[0] = f[1] = 0;
            queue<pii> q;
            q.push({i,0});
            while(!q.empty()){
                int node = q.front().fi;
                int dist = q.front().se;
                q.pop();
                if(!vis[node]){
                    f[dist%2]++;
                    vis[node] = true;
                    for(auto j : adj[node]){
                        q.push({j,dist+1});
                    }
                }
            }
            ans += (f[0] * (f[0]-1))/2;
            ans += (f[1] * (f[1]-1))/2;
        }
    }

    cout<<1<<" "<<ans<<newl;
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    int mx = 0;
    for(int i=0;i<m;++i){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
        mx = max({mx,(int)adj[u].size(),(int)adj[v].size()});
    }

    if(is_bipartite()){
        if(mx == 0){
            ll ans = 0;
            if(n >= 3){
                ans = n * (n-1) * (n-2);
                ans/=6;
            }
            cout<<3<<" "<<ans<<newl;
        }
        else if(mx == 1) solve_1();
        else solve_2();
    }
    else cout<<"0 1\n";
    return 0;

}
