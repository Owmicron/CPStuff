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
    if(97 <= int(x) && int(x) <= 122) return int(x-96)+26;
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
int f[60],q,n;
ll fac[100010],dp[100010],base,ans[60][60],md = 1e9+7;
str s;
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fac[0] = 1;
    for(int i=1;i<=1e5;++i) fac[i] = (fac[i-1] * (ll) i) % md;

    cin>>s; n = s.size();
    for(int i=0;i<s.size();++i){
        int d = numerize(s[i]);
        f[d]++;
    }

    base = (fac[n/2] * fac[n/2]) % md;
    base = (base * 2) % md;

    for(int i=1;i<=52;++i){
        ll temp = invmod(fac[f[i]],md);
        base = (base * temp) % md;
    }

    dp[0] = 1;
    for(int i=1;i<=52;++i){
        if(!f[i]) continue;
        for(int j=n;j>=0;--j){
            if(j < f[i]) break;
            dp[j] = (dp[j] + dp[j - f[i]]) % md;
        }
    }


    for(int i=1;i<=52;++i){
        if(!f[i]) continue;
        ll temp[n+2];
        for(int j=0;j<=n;++j) temp[j] = dp[j];
        for(int j=f[i];j<=n;++j){
            temp[j] = temp[j] - temp[j-f[i]];
            if(temp[j] < 0) temp[j] = md + temp[j];
        }
        ll ress = (base * temp[n/2]) % md;
        ans[i][i] = ress;
        for(int j=i+1;j<=52;++j){
            if(!f[j]) continue;
            for(int k=f[j];k<=n;++k){
                temp[k] = temp[k] - temp[k-f[j]];
                if(temp[k] < 0) temp[k] = md + temp[k];
            }
            ll res = (base * temp[n/2]) % md;
            ans[i][j] = res;
            for(int k=n;k>=0;--k){
                if(k < f[j]) break;
                temp[k] = (temp[k] + temp[k - f[j]]) % md;
            }
        }
    }

    cin>>q;
    for(int i=1;i<=q;++i){
        int x,y; cin>>x>>y; x--,y--;
        int a = numerize(s[x]);
        int b = numerize(s[y]);
        if(a > b) swap(a,b);
        ll res = ans[a][b];
        cout<<res<<newl;
    }


    return 0;
}