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
int q;
ll binser(ll sum, ll coef, ll b, ll m){
    ll l = 1;
    ll r = m;
    ll res = 1;
    while(l<=r){
        ll mid = (l+r)/2;
        ll tsum = sum + (coef * mid);
        if(tsum <= b) res = mid, l = mid+1;
        else r = mid-1;
    }
    return res;
}
void construct(ll a, ll b, ll m, ll k){
    vll r;
    ll sum = (1LL << (max(k-2,(ll)0)));
    sum *= a;

    for(int i=0;i<k-1;++i) r.pb(1LL<<max(i-1,0)), sum += (ll) (1LL<<max(i-1,0));

    vll ans;
    for(int i=r.size()-1;i>=0;--i){
        ll coef = r[i];
        sum -= r[i];
        ll res = binser(sum,coef,b,m);
        sum += res * coef;
        ans.pb(res);
    }

    vll fin; sum = a;
    fin.pb(a);
    for(auto i : ans) {
        fin.pb(sum + i);
        sum += fin.back();
    }

    for(auto i : fin){
        if(i > 1e14) {cout<<-1<<newl; return;}
    }

    cout<<k;
    for(auto i : fin) cout<<" "<<i;cout<<newl;
}
void solve(ll a, ll b, ll m){
    ll coef = 0;
    for(int i=1;i<=50;++i){
        ll c = max((ll)1,coef);
        ll mn = (c * a) + (coef);
        ll mx = (c * a) + (coef * m);
        if(mn <= b && b <= mx){
            construct(a,b,m,i);
            return;
        }

        coef *= 2;
        if(!coef) coef = 1;
    }

    cout<<-1<<newl;
    return;
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>q;
    while(q--){
        ll a,b,m; cin>>a>>b>>m;
        solve(a,b,m);
    }
    return 0;

}
