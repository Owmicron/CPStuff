#include<bits/stdc++.h>
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
ll gcd (ll num1, ll num2){
    if(num1 < num2) swap(num1,num2); ll num3 = num1 % num2 ;
    while(num3 > 0){ num1 = num2; num2 = num3; num3 = num1 % num2;}
    return num2;
}
ll lcm (ll num1 , ll num2){return (ll) (num1/__gcd(num1,num2))*num2;}
// end of Template

// lazy vars
int g[100010], stree[4 * 100010], lazy[4 * 100010], inf = 1e9 + 10, lf, rg, v;
int sstree[4 * 100010], slazy[4 * 100010],MAX;
// 1 is for min
// 2 is for max
void build1(int now, int l, int r) {
	if(l == r) {
		stree[now] = g[l];
		return;
	}
	int m = (l + r) / 2;
	build1(now * 2, l, m);
	build1(now * 2 + 1, m + 1, r);
	stree[now] = min(stree[now * 2], stree[now * 2 + 1]);
}
void build2(int now, int l, int r) {
	if(l == r) {
		sstree[now] = g[l];
		return;
	}
	int m = (l + r) / 2;
	build2(now * 2, l, m);
	build2(now * 2 + 1, m + 1, r);
	sstree[now] = max(sstree[now * 2], sstree[now * 2 + 1]);
}
void update1(int now, int l, int r, int st, int en, int val) {
	if(lazy[now] != 0) {
		stree[now] += lazy[now];
        if(l!=r) {
            lazy[now * 2] += lazy[now];
            lazy[now * 2 + 1] += lazy[now];
        }
        lazy[now] = 0;
	}
	if(en < l || r < st) {
		return;
	}
	if(st <= l && r <= en){
        stree[now] += val;
        if(l != r){
            lazy[now * 2] += val;
            lazy[now * 2 + 1] += val;
        }
        return;
    }
    int m = (l + r) / 2;
    update1(now * 2, l, m, st, en, val);
    update1(now * 2 + 1, m + 1, r, st, en, val);
    stree[now] = min(stree[now * 2], stree[now * 2 + 1]);
}
void update2(int now, int l, int r, int st, int en, int val) {
	if(slazy[now] != 0) {
		sstree[now] += slazy[now];
        if(l!=r) {
            slazy[now * 2] += slazy[now];
            slazy[now * 2 + 1] += slazy[now];
        }
        slazy[now] = 0;
	}
	if(en < l || r < st) {
		return;
	}
	if(st <= l && r <= en){
        sstree[now] += val;
        if(l != r){
            slazy[now * 2] += val;
            slazy[now * 2 + 1] += val;
        }
        return;
    }
    int m = (l + r) / 2;
    update2(now * 2, l, m, st, en, val);
    update2(now * 2 + 1, m + 1, r, st, en, val);
    sstree[now] = max(sstree[now * 2], sstree[now * 2 + 1]);
}

int querymin(int now, int l, int r, int st, int en) {
	if(en < l || r < st) {
		return inf;
	}
	if(lazy[now] != 0) {
		stree[now] += lazy[now];
        if(l!=r) {
            lazy[now * 2] += lazy[now];
            lazy[now * 2 + 1] += lazy[now];
        }
        lazy[now] = 0;
	}
	if(st <= l && r <= en) {
		return stree[now];
	}
	int m = (l + r) / 2;
    return min(querymin(now * 2, l, m, st, en), querymin(now * 2 + 1, m + 1, r, st, en));
}
int querymax(int now, int l, int r, int st, int en) {
	if(en < l || r < st) {
		return -inf;
	}
	if(lazy[now] != 0) {
		sstree[now] += slazy[now];
        if(l!=r) {
            slazy[now * 2] += slazy[now];
            slazy[now * 2 + 1] += slazy[now];
        }
        slazy[now] = 0;
	}
	if(st <= l && r <= en) {
		return sstree[now];
	}
	int m = (l + r) / 2;
    return max(querymax(now * 2, l, m, st, en), querymax(now * 2 + 1, m + 1, r, st, en));
}

int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    MAX = 1e6+2;

    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>g[i];
    build1(1,1,n);
    update1(1,1,n,4,4,-4);
    cout<<querymin(1,1,n,3,n);
}
