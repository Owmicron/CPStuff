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
    if( 97 <= int(x) && int(x) <= 122)return char(x-32);
    if( 65 <= int(x) && int(x) <= 90)return x;
    return -1;
}
char to_lower (char x){
    if( 97 <= int(x) && int(x) <= 122)return x;
    if( 65 <= int(x) && int(x) <= 90)return char(x+32);
    return -1;
}
int numerize (char x){
    if(48 <= int(x) && int(x) <= 57)return int(x-'0');
    if( 97 <= int(x) && int(x) <= 122)return int(x-96);
    if( 65 <= int(x) && int(x) <= 90)return int(x-64);
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
int n,m,p;
ll ans = 0;
int mpower[200010],mdefense[200010];
pii power[200010];
pii defense[200010];
vector < pair < pii , int> > mons1,mons2;
int binserp(int x){
    int l = 1;
    int r = n;
    int res = -1;
    while(l<=r){
        int mid = (l+r)/2;
        if(mpower[mid] > x) {res = mid; r = mid-1;}
        else l = mid+1;
    }
    return res;
}
int binserd(int x){
    int l = 1;
    int r = m;
    int res = -1;
    while(l<=r){
        int mid = (l+r)/2;
        if(mdefense[mid] > x) {res = mid; r = mid-1;}
        else l = mid+1;
    }
    return res;
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m>>p;
    for(int i=1;i<=n;++i){
        int temp1,temp2;
        cin>>temp1>>temp2;
        power[i] = mp(temp2,temp1);
    }
    for(int i=1;i<=m;i++){
        int temp1,temp2;
        cin>>temp1>>temp2;
        defense[i] = mp(temp2,temp1);
    }
    sort(power+1,power+1+n);
    sort(defense+1,defense+1+m);
    for(int i=1;i<=p;i++){
        int temp1, temp2, temp3;
        cin>>temp1>>temp2>>temp3;
        mons1.pb(mp(mp(temp1,temp2),temp3));
        mons2.pb(mp(mp(temp2,temp1),temp3));
    }
    sort(mons1.begin(),mons1.end());
    sort(mons2.begin(),mons2.end());

    for(int i=1;i<=n;i++){
        mpower[i] = max(mpower[i-1],power[i].se);
    }
    for(int i=1;i<=m;i++){
        mdefense[i] = max(mdefense[i-1],defense[i].se);
    }

    int m = 0;
    ll coin = 0;
    for(int i=0;i<mons1.size();i++){
        coin += mons1[i].se;
        m = max(m,mons1[i].fs);
        int idx1,idx2;
        idx1 = binserp(mons1[i].ff);
        idx2 = binserd(m);
        if(idx1 < 0 || idx2 < 0) break;
        ll temp = power[idx1].fi + defense[idx2].fi;
        ll profit = coin - temp;
        ans = max(ans,profit);
    }

    m = 0;
    coin = 0;
    for(int i=0;i<mons2.size();i++){
        coin += mons2[i].se;
        m = max(m,mons2[i].fs);
        int idx1,idx2;
        idx1 = binserd(mons2[i].ff);
        idx2 = binserp(m);
        if(idx1 < 0 || idx2 < 0) break;
        ll temp = power[idx2].fi + defense[idx1].fi;
        ll profit = coin - temp;
        ans = max(ans,profit);
    }
    cout<<ans<<newl;
}
