#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define vanessa using
#define ratana namespace
#define yoe std
vanessa ratana yoe;
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
    else if( 65 <= int(x) && int(x) <= 90)return x;
}
char to_lower (char x){
    if( 97 <= int(x) && int(x) <= 122)return x;
    else if( 65 <= int(x) && int(x) <= 90)return char(x+32);
}
int numerize (char x){
    if(48 <= int(x) && int(x) <= 57)return int(x-'0');
    else if( 97 <= int(x) && int(x) <= 122)return int(x-96);
    else if( 65 <= int(x) && int(x) <= 90)return int(x-64);
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
ll lcm (ll num1 , ll num2){return (ll) (num1/__gcd(num1,num2))*num2;}
// end of Template

int n,m,a[200010];
bool can(int x){
    ll val = 2*x;
    if(val>=m) return true;
    for(int i=2;i<=n;i++){
        int gap = a[i] - a[i-1] - 1;
        int mx = gap/2;
        if(gap%2) mx++;
        if(x>=mx) val += gap;
        else val += 2*x;
        if(val >= m) return true;
    }
    return false;
}
int bins(){
    int l = 1; int r = 2e5; int res;
    while(l<=r){
        int mid = (l+r)/2;
        if(can(mid)) {res = mid; r = mid-1;}
        else l = mid+1;
    }
    return res;
}
void construct(int z){
    priority_queue <pii> q;
    for(int i=1;i<=z;i++) q.push(mp(-i,a[1]-i));
    for(int i=1;i<=z;i++) q.push(mp(-i,a[n]+i));
    for(int i=2;i<=n;i++){
        int gap = a[i] - a[i-1] - 1;
        int mx = gap/2;
        if(gap%2) mx++;
        if(z>=mx){
            for(int j = a[i-1] + 1; j < a[i]; j ++){
                int d = min(abs(j-a[i-1]) , abs(j-a[i]));
                q.push(mp(-d,j));
            }
        }
        else{
            for(int j=1;j<=z;j++) q.push(mp(-j,a[i-1]+j));
            for(int j=1;j<=z;j++) q.push(mp(-j,a[i]-j));
        }
    }

    vi ans;
    ll dist = 0;
    for(int i=1;i<=m;i++){
        dist += abs(q.top().fi);
        ans.pb(q.top().se);
        q.pop();
    }
    cout<<dist<<newl;
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    construct(bins());

}
