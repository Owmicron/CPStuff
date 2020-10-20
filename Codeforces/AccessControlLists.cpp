#include<bits/stdc++.h>
#include<stdio.h>

//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define pb push_back
#define fi first
#define se second
#define ll long long
#define tp top()
#define fr front()
#define pii pair<int,int>
#define pip pair<int,pii>
#define ppi pair<pii,int>
#define ppp pair<pii,pii>
#define sz size()
#define rep(i,a,b) for(int i = a; i < b; ++i)
using namespace std;

void base(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

set<ll> lists;
map<ll,int> mmap;

#define N 300020

int st[4*N];

void build(int v, int l, int r){
	if (l==r){
		st[v]=1;
		return;
	}
	int m = (l+r)/2;
	build(v<<1,l,m);
	build(v<<1|1,m+1,r);
	st[v]=1;
}

void update(int v, int l, int r,int ss, int se, int state){
	if (ss>se) return;

	if (ss == l && se == r){
		st[v]=state;
		return;
	}

	int m = (l+r)/2;
	if (st[v] != 0){
		st[v<<1]=st[v];
		st[v<<1|1]=st[v];
	}
	st[v]=0;

	update(v<<1,l,m,ss,min(m,se),state);
	update(v<<1|1,m+1,r,max(m+1,ss),se,state);
}

int query(int v, int l, int r, int x){
	if (l == r) {
		return st[v];
	}

	if (st[v] != 0) return st[v];
	int m = (l+r)/2;
	if (x <= m)
		return query(v<<1,l,m,x);
	else
		return query(v<<1|1,m+1,r,x);
}

int main()
{
//	base();
	int n,m;
//	freopen("access.in", "r", stdin);
//    freopen("access.out", "w", stdout);

	scanf("%d",&n);
	vector<pair<int,pair<ll,ll> > > vec;
	rep(i,0,n){
		char s[20];
		ll a,b,c,d,e;
		scanf("%s from %lld.%lld.%lld.%lld",s,&a,&b,&c,&d);
		ll mask=1;
		if (getchar() != '\n'){
			scanf("%lld",&e);
			mask = (1LL<<(32-e));
		}
		ll bit = a*(1<<24)+b*(1<<16)+c*(1<<8)+d;
		lists.insert(bit);
		lists.insert(bit+mask-1);
//		cout<<bit<<" "<<bit+mask-1<<'\n';
		if (s[0]=='a'){
			vec.pb({1,{bit,bit+mask-1}});
		} else{
			vec.pb({-1,{bit,bit+mask-1}});
		}
	}

	scanf("%d",&m);
	vector<ll> q;
	rep(i,0,m){
		ll a,b,c,d;
		scanf("%lld.%lld.%lld.%lld",&a,&b,&c,&d);
		ll bit = a*(1<<24)+b*(1<<16)+c*(1<<8)+d;
//		cout<<bit<<'\n';
		lists.insert(bit);
		q.pb(bit);
	}
	int id=0;
	for(auto it=lists.begin(); it!=lists.end(); ++it){
		mmap[(*it)]=id++;
	}
	build(1,0,id-1);
	for(int i=n-1; i>=0; i--){
		int stat = vec[i].fi;
		ll fir = vec[i].se.fi;
		ll sec = vec[i].se.se;
		update(1,0,id-1,mmap[fir],mmap[sec],stat);
	}
	rep(i,0,m){
		int ans = query(1,0,id-1,mmap[q[i]]);
		if (ans==1)cout<<'A';
		else cout<<"D";
	}
	cout<<'\n';


	return 0;
}
