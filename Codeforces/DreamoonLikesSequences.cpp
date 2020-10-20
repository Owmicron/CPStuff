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
#define all(x) (x).begin(), x.end()

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
ll bit_count(ll x){
    ll res = 0;
    while(x){
        res++;
        x/=2;
    }
    return res;
}
ll solve(ll d, ll md){
    int n = 0;
    ll cnt[40];
    for(int i=0;i<=40;i++){
        n++;
        int bit = i+1;
        //cout<<d<<" "<<bit_count(d)<<newl;
        if(bit_count(d) > bit) cnt[n] = (1<<i);
        else{
            cnt[n] = d - ((1<<i)-1);
            break;
        }
    }

    ll sum[40][40];
    ll ret[40][40];
    ll res = 0;
    for(int i=1;i<=n;i++){
        res = (res + cnt[i]) % md;
        ret[1][i] = (cnt[i] % md);
        //cout<<1<<" "<<i<<" = "<<ret[1][i]<<newl;
    }

    int idx = 1;
    for(int i=2;i<=n;i++){
        int l = 2;
        int r = n+2-i;
        for(int j=r;j>=l;j--){
            if(j==r) sum[i][j] = (ret[i-1][j] % md);
            else sum[i][j] = (sum[i][j+1] + ret[i-1][j]) % md;
        }
        for(int j=1;j<=n-i+1;j++){
            ret[i][j] = ((cnt[j] % md) * (sum[i][j+1] % md)) % md;
            res = (res + ret[i][j]) % md;
            //cout<<i<<" "<<j<<" = "<<ret[i][j]<<newl;
        }
    }

    return res;
    //cout<<res<<newl;

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
        ll d,m;
        cin>>d>>m;
        cout<<solve(d,m)<<newl;
    }
    return 0;
}
