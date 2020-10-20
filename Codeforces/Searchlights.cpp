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
int n,m,mxl[2010];
pii src[2010],robber[2010];
int ans = INT_MAX;
vpii light;

int N = 1e6 + 3;
int stree[1000010 * 4], lazy[1000010 * 4],an[1000010];
void propagate(int now, int l, int r){
    if(lazy[now]){
        stree[now] = max(stree[now],lazy[now]);
        if(l != r) {
            lazy[now*2] = max(lazy[now*2],lazy[now]);
            lazy[now*2+1] = max(lazy[now*2+1],lazy[now]);
        }
        lazy[now] = 0;
    }
    return;
}
void bringall(int now, int l, int r){
    propagate(now,l,r);
    if(l == r) {
        an[l] = stree[now];
        return;
    }
    int mid = (l + r) >> 1;
    bringall(now*2,l,mid);
    bringall(now*2+1,mid+1,r);
    return;
}
void update(int now, int l, int r, int ql, int qr, int val){
    propagate(now,l,r);
    if(ql > r || qr < l) return;
    if(ql <= l && r <= qr){
        lazy[now] = val;
        propagate(now,l,r);
        return;
    }
    int mid = (l + r) >> 1;
    update(now*2,l,mid,ql,qr,val);
    update(now*2+1,mid+1,r,ql,qr,val);
    stree[now] = max(stree[now*2],stree[now*2+1]);
    return;
}
int query(int now, int l, int r, int ql, int qr){
    if(ql > r || qr < l) return 0;
    propagate(now,l,r);
    if(ql <= l && r <= qr) return stree[now];
    int mid = (l+r) >> 1;
    return max(query(now*2,l,mid,ql,qr) , query(now*2+1,mid+1,r,ql,qr) );
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> robber[i].fi >> robber[i].se;
    for(int i = 1; i <= m; ++i){
        int r, c; cin >> r >> c;
        src[i] = {r,c};
    }
    src[0] = {-1,-1};
    sort(src,src+m+1);

    light.pb(src[0]);
    for(int i = 1; i <= m; ++i){
        if(src[i].fi == light.back().fi) light.pob();
        light.pb(src[i]);
    }

    for(int i = (int) light.size() - 1; i >= 0; --i) mxl[i] = max(mxl[i+1],light[i].se);
    mxl[light.size()] = -1;

    for(int i = 1; i <= n; ++i){
        vpii v;
        for(int j = 0; j < light.size(); ++j){
            int r = robber[i].fi;
            int c = robber[i].se;
            int mv = max(light[j].fi + 1 - r, 0);
            int temp = max(0,mxl[j+1] + 1 - c);

            if(!v.empty() && mv == v.back().fi){
                if(temp <= v.back().se) v.pob();
            }
            v.pb({mv,temp});
            //update(1,0,N,mv,N,temp);
        }

        v.pb({N,0});
        for(int j = 0; j < v.size(); ++j){
            if(j == (int) v.size() - 1) break;
            int l = v[j].fi;
            int r = v[j+1].fi - 1;
            int temp = v[j].se;
            update(1,0,N,l,r,temp);
        }
    }

    bringall(1,0,N);
    for(int i = 0; i <= N; ++i){
        int q = an[i];
        //watch(q);
        q += i;
        ans = min(ans,q);
    }
    cout << ans << newl;

    return 0;
}
