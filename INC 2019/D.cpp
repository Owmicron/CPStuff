#include<bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
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

int n,m,u,v,d,num[100005],low[100005],par[100005],child,asdf=1;
vector<int> adjlist[100005];
vector< pair< int, int> > out;
bool flag;
char q,p;

void dfs(int now)
{
	num[now]=d;
	low[now]=d;
	d++;
	child=0;
	flag=false;
	for(int i=0;i<adjlist[now].size();i++)
	{
		int next=adjlist[now][i];
		if(num[next]==-1)
		{
			par[next]=now;
			dfs(next);
			child++;
			if(low[next]>num[now])
			{
				int mini=min(now,next);
				int maks=max(now,next);
				out.push_back(make_pair(mini,maks));
			}
			low[now]=min(low[now],low[next]);
		}
		else if(next!=par[now])
		{
			low[now]=min(low[now],num[next]);
		}
	}
}
map < pii , bool > bridge;
vpii edges;
vi adj[100010];
bool vis[100010];
int group[100010];
int gr;
int Q;
bool bfs(int x){
    queue <int> q;
    q.push(x);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(!vis[node]){
            vis[node] = true;
            group[node] = gr;
            for(int i=0;i<adj[node].size();i++){
                q.push(adj[node][i]);
            }
        }
    }
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	d=0;
	memset(num,-1,sizeof(num));
	memset(low,-1,sizeof(low));
	for(int i=0;i<n;i++)
	{
		par[i]=i;
	}
	cin >> n >> m >> Q;
	for(int i = 0;i<m;i++) {
		cin>>u>>v;
		edges.pb(mp(u,v));
		u--;
		v--;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}
	for(int i=0;i<n;i++)
	{
		if(num[i]==-1)
		{
			dfs(i);
		}
	}
	sort(out.begin(),out.end());
	//cout<<out.size()<<" critical links"<<endl;
	for(int i=0;i<out.size();i++)
	{
        pii temp = mp ( out[i].fi+1 , out[i].se+1 );
        bridge[temp] = true;
		//cout<<out[i].first+1<<" - "<<out[i].second+1<<endl;
	}

	for(int i=0;i<edges.size();i++){
        if(!bridge[edges[i]]){

            int u,v;
            u = edges[i].fi;
            v = edges[i].se;
            adj[u].pb(v);
            adj[v].pb(u);
        }
	}

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            gr++;
            bfs(i);
        }
    }


    for(int i=1;i<=Q;i++){
        int u,v;
        cin>>u>>v;
        if(group[u] == group[v]){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }


}
