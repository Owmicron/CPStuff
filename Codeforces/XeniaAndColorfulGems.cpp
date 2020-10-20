#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
    if( 97 <= int(x) && int(x) <= 122) return int(x-96);
    if( 65 <= int(x) && int(x) <= 90) return int(x-64);
    return -1;
}
bool isect (int l1, int r1, int l2, int r2){
    pii p1,p2;
    p1 = mp(l1,r1); p2 = mp(l2,r2);
    if(p1>p2)swap(p1,p2);
    if(p2.fi <= p1.se)return true;
    else return false;
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
vi v[4];
ll INF = 2e18;
ll ans;
ll sqr(ll x){
    return (ll) x * x;
}
ll cost(ll a, ll b, ll c){
    ll res = sqr(a-b) + sqr(b-c) + sqr(a-c);
    return res;
}
ll binser(int idx1, int idx2, int idx3, int idx){
    ll piv = v[idx2][idx];

    int l = 0;
    int r = v[idx1].size()-1;
    ll res = -1;
    while(l<=r){
        int mid = (l+r)/2;
        if(v[idx1][mid] <= piv) res = mid, l = mid+1;
        else r = mid-1;
    }
    if(res == -1) return INF;
    ll a = v[idx1][res];

    l = 0;
    r = v[idx3].size()-1;
    res = -1;
    while(l<=r){
        int mid = (l+r)/2;
        if(piv <= v[idx3][mid]) res = mid, r = mid-1;
        else l = mid+1;
    }
    if(res == -1) return INF;
    ll b = v[idx3][res];
    return cost(piv,a,b);
}
void solve(int idx1, int idx2, int idx3){
    for(int i=0;i<v[idx2].size();i++){
        ans = min(ans,binser(idx1,idx2,idx3,i));
    }
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int nr,ng,nb,temp;
        cin>>nr>>ng>>nb;
        for(int i=1;i<=3;i++) v[i].clear();
        for(int i=1;i<=nr;i++) cin>>temp, v[1].pb(temp); sort(all(v[1]));
        for(int i=1;i<=ng;i++) cin>>temp, v[2].pb(temp); sort(all(v[2]));
        for(int i=1;i<=nb;i++) cin>>temp, v[3].pb(temp); sort(all(v[3]));
        ans = INF;
        solve(1,2,3);
        solve(1,3,2);
        solve(2,1,3);
        solve(2,3,1);
        solve(3,1,2);
        solve(3,2,1);
        cout<<ans<<newl;

    }


    return 0;
}
