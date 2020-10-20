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
bool isprime[32010];
bool erased[200010];
vi prime;
void sieve(int x){
    for(int i = 2; i <= x; ++i) isprime[i] = true;
    for(int i = 2; i <= x; ++i){
        if(isprime[i]){
            prime.pb(i);
            for(int j = 2 * i; j <= x; j += i) isprime[i] = false;
        }
    }
}
void solve(int x){
    int ori = x;
    vi fac;
    for(auto i : prime){
        if(x % i == 0){
            fac.pb(i);
            while(x % i == 0) x /= i;
        }
    }
    if(x > 1) fac.pb(x);

    x = ori;
    vi div;
    for(int i = 2; i * i <= x; ++i){
        if(x % i == 0){
            div.pb(i);
            if(i != x/i) div.pb(x/i);
        }
    }
    div.pb(x);
    for(int i = 0; i < div.size(); ++i) erased[i] = false;

    if(fac.size() == 1){
        for(auto i : div) cout << i << " "; cout << newl;
        cout << 0 << newl;
        return;
    }

    if(fac.size() == 2){
        if (x == fac[0] * fac[1]){
            for(auto i : div) cout << i << " "; cout << newl;
            cout << 1 << newl;
            return;
        }

        vi ab;
        for(int i = 0; i < div.size(); ++i){
            if(div[i] == fac[0]) erased[i] = true;
            if(div[i] == fac[1]) erased[i] = true;
            if(div[i] % (fac[0] * fac[1]) == 0) {
                if(ab.size() < 2) ab.pb(div[i]), erased[i] = true;
            }
        }

        cout << fac[0] << " ";
        for(int i = 0; i < div.size(); ++i){
            if(erased[i]) continue;
            if(div[i] % fac[0] == 0) {
                erased[i] = true;
                cout << div[i] << " ";
            }
        }
        cout << ab[0] << " ";
        cout << fac[1] << " ";

        for(int i = 0; i < div.size(); ++i){
            if(erased[i]) continue;
            if(div[i] % fac[1] == 0){
                erased[i] = true;
                cout << div[i] << " ";
            }
        }
        cout << ab[1] << " ";
        cout << newl;
        cout << 0 << newl;
        return;
    }

    vpii v;
    for(int i = 0; i < fac.size(); ++i){
        int cur = fac[i];
        int inter;
        if(i == fac.size() - 1) inter = fac[0];
        else inter = fac[i+1];
        inter *= fac[i];
        v.pb({cur,inter});
    }

    int last = v.back().se;
    for(int i = 0; i < v.size(); ++i){
        int cur = v[i].fi;
        int inter = v[i].se;

        cout << cur << " ";
        for(int j = 0; j < div.size(); ++j){
            if(erased[j]) continue;
            if(div[j] == last) continue;
            if(div[j] == cur) {erased[j] = true; continue;}
            if(div[j] == inter) {erased[j] = true; continue;}
            if(div[j] % fac[i] == 0) {cout << div[j] << " "; erased[j] = true;}
        }
        cout << inter << " ";
    }
    cout << newl;
    cout << 0 << newl;

}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sieve(32000);
    int t; cin >> t;
    while(t--){
        int x; cin >> x;
        solve(x);
    }

    return 0;
}
