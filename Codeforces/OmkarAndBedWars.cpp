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
int t,n;
vector <char> v;
bool calc[3][200010];
int memo[3][200010],INF = 1e7;
void resetdp(){
    for(int i = 0; i <= n; ++i){
        calc[0][i] = calc[1][i] = calc[2][i] = false;
    }
}
int dp(int typ, int idx){
    if(idx < 0) return INF;
    if(idx == 0) return 0;
    if(calc[typ][idx]) return memo[typ][idx];

    int &res = memo[typ][idx];
    res = INF;
    calc[typ][idx] = true;
    if(typ == 1){
        if(idx < 3) return res;
        int temp = 0;
        if(v[idx-1] == 'R') ++temp;
        if(v[idx-2] == 'L') ++temp;
        res = min(res, temp + dp(0,idx-3));
        res = min(res, temp + dp(1,idx-3));
        res = min(res, temp + dp(2,idx-3));
    }
    else if(typ == 0){
        if(idx < 2) return res;
        int temp = 0;
        if(v[idx-1] == 'R') ++temp;
        if(v[idx-2] == 'L') ++temp;
        res = min(res, temp + dp(0,idx-2));
        res = min(res, temp + dp(1,idx-2));
        res = min(res, temp + dp(2,idx-2));
    }
    if(typ == 2){
        if(idx < 4) return res;
        int temp = 0;
        if(v[idx-1] != 'L') ++temp;
        if(v[idx-2] != 'L') ++temp;
        if(v[idx-3] != 'R') ++temp;
        if(v[idx-4] != 'R') ++temp;
        res = min(res, temp + dp(0,idx-4));
        res = min(res, temp + dp(1,idx-4));
        res = min(res, temp + dp(2,idx-4));
    }

    return res;
}
void shift(){
    vector<char> v2; v2.pb(v.back());
    for(int i = 0; i < (int) v.size()-1; ++i) v2.pb(v[i]);
    v.clear();
    v = v2;
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--){
        v.clear();
        resetdp();
        cin >> n;
        str s; cin >> s;
        for(int i = 0 ; i < s.size(); ++i) v.pb(s[i]);

        int ans = INF;
        ans = min({dp(0,n) , dp(1,n), dp(2,n)});

        for(int i = 0; i < 5; ++i){
            shift();
            resetdp();
            ans = min({ans, dp(0,n) , dp(1,n), dp(2,n)});
        }
        cout << ans << newl;
    }

    return 0;
}
