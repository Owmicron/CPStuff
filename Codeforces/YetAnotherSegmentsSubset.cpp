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
bool isect (pii p1, pii p2){
    if(p1>p2)swap(p1,p2);

    if(p2.fi > p1.se) return false;
    if(p1.fi == p2.fi || p1.se == p2.se) return false;
    return !(p2.se <= p1.se);
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
vi adj[4000];
int color[4000],f[4000],n;
pii p[4000];
int solve_component(vi &v){
    vpii deg;
    for(auto i : v){
        color[i] = 0;
        deg.pb({adj[i].size(),i});
    }
    sort(all(deg));
    reverse(all(deg));

//    for(auto i : deg){
//        cout<<i.fi<<" - "<<i.se<<newl;
//    }
    bool colored = true;
    int idx = 0;
    while(colored){
        ++idx;
        colored = false;
        for(auto i : deg){
            if(color[i.se] == 0){
                bool valid = true;
                for(auto j : adj[i.se]){
                    if(color[j] == idx) {valid = false; break;}
                }
                if(valid) {colored = true; color[i.se] = idx; f[idx]++;}
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= idx; ++i){
        ans = max(ans,f[i]);
        f[i] = 0;
    }
    return ans;
}
int solve(){
    bool vis[4000];
    for(int i=1;i<=n;++i) vis[i] = false;

    int ans = 0;
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            vi v;
            queue <int> q;
            q.push(i);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                if(!vis[node]){
                    v.pb(node);
                    vis[node] = true;
                    for(auto j : adj[node]) q.push(j);
                }
            }
//            cout<<"komponen\n";
//            for(auto j : v) cout<<j<<newl;
//            watch(solve_component(v));
            ans += solve_component(v);
            v.clear();
        }
    }

    return ans;
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; ++i){
            int l , r; cin >> l >> r;
            p[i] = {l,r};
            adj[i].clear();
        }

        for(int i = 1 ; i <= n; ++i){
            for(int j = i + 1; j <= n; ++j){
                if(isect (p[i],p[j])){
                    adj[i].pb(j);
                    adj[j].pb(i);
//                    cout<<i<<" & "<<j<<newl;
                }
            }
        }

        cout<<solve()<<newl;


    }

    return 0;
}
