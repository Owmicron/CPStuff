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
#define watch(x) cout << (#x) << " is : " << (x) << newl

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

ll h[100010],n,a,r,m;
ll cost(ll x){
    ll res = 0;
    for(int i=1;i<=n;++i){
        if(h[i] <= x) res += (x-h[i])*a;
        else res += (h[i]-x)*r;
    }
    return res;
}
ll ternary(){
    ll lo = 0;
    ll hi = 1e9;
    while(lo + 5 <= hi){
        ll d = (hi-lo+1) / 3;
        ll mid1 = lo + d;
        ll mid2 = lo + 2*d;

        if(cost(mid1) < cost(mid2)) hi = mid2-1;
        else lo = mid1 + 1;
    }

    ll res = 1e16;
    for(int i=lo;i<=hi;i++) res = min(res,cost(i));
    return res;
}
ll cost2(ll x){
    ll larg = 0;
    ll debt = 0;
    for(int i=1;i<=n;++i){
        if(x < h[i]) larg += h[i]-x;
    }
    ll res = 0;
    for(int i=1;i<=n;++i){
        if(h[i] < x){
            ll need = x - h[i];
            if(need <= larg) res += (m * need), larg -= need;
            else{
                res += (m*larg), need-=larg, debt += need;
            }
        }
    }

    if(larg) res += (r*larg);
    if(debt) res += (debt*a);

    return res;
}
ll ternary2(){
    ll lo = 0;
    ll hi = 1e9;
    while(lo + 5 <= hi){
        ll d = (hi-lo+1) / 3;
        ll mid1 = lo + d;
        ll mid2 = lo + 2*d;

        if(cost2(mid1) < cost2(mid2)) hi = mid2-1;
        else lo = mid1 + 1;
    }

    ll res = 1e16;
    for(int i=lo;i<=hi;i++) res = min(res,cost2(i));
    return res;
}
ll alt(){
    ll arr[n+2];
    ll sum = 0;
    for(int i=1;i<=n;++i) sum += h[i];
    for(int i=1;i<=n;++i){
        arr[i] = sum / n;
    }
    ll mod = sum % n;
    for(int i=n;i>n-mod;--i){
        arr[i]++;
    }

    //for(int i=1;i<=n;++i) cout<<arr[i]<<" ";cout<<newl;
    ll res = 0;
    for(int i=1;i<=n;++i){
        if(arr[i] < h[i]) res += (h[i] - arr[i]) * m;
    }
    ll p = min(r * mod, (n-mod) * a);
    res += p;
    return res;

}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>a>>r>>m;
    for(int i=1;i<=n;++i) cin>>h[i];
    sort(h+1,h+1+n);

    ll ans = ternary();
    ans = min(ans,alt());
    ans = min(ans,ternary2());
    cout<<ans<<newl;

    return 0;
}
