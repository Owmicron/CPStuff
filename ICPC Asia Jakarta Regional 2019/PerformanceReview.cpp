#include<bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
int n,m,q,randall,a[100010],p[100010],r[100010];
vi b[100010];

int g[100010], stree[4 * 100010], lazy[4 * 100010], inf = 1e9 + 10, lf, rg, v;

void build(int now, int l, int r) {
	if(l == r) {
		stree[now] = g[l];
		return;
	}
	int m = (l + r) / 2;
	build(now * 2, l, m);
	build(now * 2 + 1, m + 1, r);
	stree[now] = min(stree[now * 2], stree[now * 2 + 1]);
}

void update(int now, int l, int r, int st, int en, int val) {
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
    update(now * 2, l, m, st, en, val);
    update(now * 2 + 1, m + 1, r, st, en, val);
    stree[now] = min(stree[now * 2], stree[now * 2 + 1]);
}

int query(int now, int l, int r, int st, int en) {
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
    return min(query(now * 2, l, m, st, en), query(now * 2 + 1, m + 1, r, st, en));
}

int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  	memset(lazy, 0, sizeof(lazy));
  	cin>>n>>m>>q;
  	for(int i=1;i<=n;i++) cin>>a[i];
  	randall = a[1];
  	p[0] = 1;
  	for(int i=1;i<=n;i++) if(a[i]<randall) p[0]++;
  	for(int i=1;i<=m;i++){
  		cin>>r[i];
  		p[i] = p[i-1];
  		for(int j=1;j<=r[i];j++) {
  			int temp; cin>>temp;
  			if(temp > randall)p[i]--;
			b[i].pb(temp);
		}
		g[i] = p[i - 1] - r[i];
	}
  	build(1, 1, m);
  	for(int i=1;i<=q;i++){
		int x,y,z;
		cin>>x>>y>>z;
		int cur = b[x][y-1];
		if(cur< randall && randall < z){
			update(1, 1, m, x + 1, m, -1);
			// kurangin
		}
		else if(z < randall && randall < cur){
			update(1, 1, m, x + 1, m, 1);
			// tambahin
		}
		b[x][y-1] = z;
		if(query(1, 1, m, 1, m) <= 0) {
			cout << 0 << newl;
		}
		else {
			cout << 1 << newl;
		}
	}
}
