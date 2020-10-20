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
    if(num2==0)return 1;
    else if(num2==1)return num1;
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
int n,m,a[40100],b[40100],k;
vpii v;
vi va,vb,sma,smb;
ll da[40010],db[40010];
set <int> sa,sb;
int factors(int x){
    for(int i=1;i<=min(40000,x);++i){
        if(x % i == 0){
            int a = i;
            int b = x/i;
            if (a<=n && b<=m) v.pb(mp(a,b)), sa.insert(a),sb.insert(b);
        }
    }
}
int binser(int x, vi V, vi S){
    int res = -1;
    int l = 0;
    int r = V.size()-1;

    while(l <= r){
        int mid = (l+r)/2;
        if(V[mid] >= x) l = mid + 1, res = mid;
        else r = mid - 1;
    }
    if(res >= 0) return S[res] - ((res+1) * (x-1));
    else return 0;
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m>>k;
    factors(k);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];

    int cons = 0;
    for(int i=1;i<=n;i++){
        if(a[i]) cons++;
        else{
            if(cons) va.pb(-cons);
            cons = 0;
        }
    }
    if(cons) va.pb(-cons);
    cons = 0;
    for(int i=1;i<=m;i++){
        if(b[i]) cons++;
        else{
            if(cons) vb.pb(-cons);
            cons = 0;
        }
    }
    if(cons) vb.pb(-cons);

    sort(va.begin(),va.end());
    sort(vb.begin(),vb.end());

    for(int i=0;i<va.size();++i){
        va[i] *= -1;
        if(i==0) sma.pb(va[i]);
        else sma.pb(sma.back()+va[i]);
    }
    for(int i=0;i<vb.size();++i){
        vb[i] *= -1;
        if(i==0) smb.pb(vb[i]);
        else smb.pb(smb.back()+vb[i]);
    }

//    for(int i=0;i<va.size();i++) cout<<va[i]<<" ";cout<<newl;
//    for(int i=0;i<vb.size();i++) cout<<vb[i]<<" ";cout<<newl;
//    cout<<binser(2,va,sma);

    for(set<int> :: iterator itr = sa.begin(); itr!= sa.end(); ++itr){
        da[*itr] = binser(*itr,va,sma);
    }
    for(set<int> :: iterator itr = sb.begin(); itr!= sb.end(); ++itr){
        db[*itr] = binser(*itr,vb,smb);
    }

    ll ans = 0;
    for(int i=0;i<v.size();++i){
        ans += da[v[i].fi] * db[v[i].se];
    }
    cout<<ans<<newl;
}
