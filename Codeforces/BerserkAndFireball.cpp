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
int pos[200010],a[200010],b[200010];
ll x,y,k;
ll cost(vi v, int l, int r){
    ll mx = 0;
    for(auto i : v) mx = max(mx,(ll)i);

    if(v.size() < k){
        if(mx > l && mx > r) return -1e18;
        else{
            ll res = (ll) v.size();
            res *= y;
            return res;
        }
    }
    else{
        ll z = y * k;
        // fireball better
        if(x <= z){
            ll rem = (ll) v.size() % k;
            ll res = rem * y;
            ll sz = v.size() - rem;
            res += (sz / k) * x;
            return res;
        }
        else{
            if(mx > l && mx > r){
                ll res = x;
                ll sz = v.size() - k;

                res += sz * y;
                return res;
            }
            else{
                ll res = (ll) v.size();
                res *= y;
                return res;
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

    int n,m;
    cin>>n>>m;
    cin>>x>>k>>y;
    for(int i=1;i<=n;++i) cin>>a[i], pos[a[i]] = i;
    for(int i=1;i<=m;++i) cin>>b[i];

    vi v;
    v.pb(0);
    for(int i=1;i<=m;++i) {
        v.pb(pos[b[i]]);
        if(pos[b[i]] == 0) {cout<<-1<<newl; return 0;}
    }
    v.pb(n+1);

    //for(auto i : v) cout<<i<<" ";cout<<newl;
    for(int i=1;i<v.size();++i) if(v[i] < v[i-1]){
        cout<<-1<<newl;
        return 0;
    }

    ll ans = 0;
    for(int i=1;i<v.size();++i){
        vi temp;
        for(int j=v[i-1]+1;j<v[i];++j) temp.pb(a[j]);
        int l = a[v[i-1]];
        int r = a[v[i]];

        ll res = cost(temp,l,r);
        if(res == -1e18) {cout<<-1<<newl; return 0;}

        ans += res;
        //for(auto j : temp) cout<<j<<" ";cout<<newl;
        //watch(res);

    }

    cout<<ans<<newl;
    return 0;

}
