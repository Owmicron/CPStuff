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
int n,m;
vpii adj[2000];
bool bad = false;
int val[2000];
bool vis[2000];
//void dfs (int node, ll sum){
//    val[node] ++;
//
//    if(val[node]<2){
//        for(int i=0;i<adj[node].size();i++){
//            if(!vis[adj[node][i].fi])dfs(adj[node][i].fi,adj[node][i].se + sum);
//        }
//    }
//    else if (node == n) bad = true;
//    val[node]--;
//}
ll dist[2000];
ll INF = 1e15;
vector < pair < pii , ll > > edge;
ll bellman_ford(){
    for(int i=1;i<=n;i++) dist[i] = INF;
    dist[1] = 0;
    for(int loop=1;loop<n;loop++){
        for(int i=0;i<edge.size();i++){
            int v = edge[i].fs;
            int u = edge[i].ff;
            if(!vis[u] || !vis[v]) continue;
            ll w = edge[i].se;
            if(dist[v] > dist[u] + w) dist[v] = dist[u] + w;
        }
    }
}
bool negcycle(){
    bellman_ford();
    for(int i=0;i<edge.size();i++){
        int v = edge[i].fs;
        int u = edge[i].ff;
        ll w = edge[i].se;
        if(!vis[u] || !vis[v]) continue;
        if(dist[v] > dist[u] + w) {return true;}
    }
    return false;
}
vi rev[2000];
void listbad(){
    queue <int> q;
    q.push(n);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(!vis[node]){
            vis[node] = true;
            for(int i=0;i<rev[node].size();i++){
                q.push(rev[node][i]);
            }
        }
    }
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w; cin>>u>>v>>w;
        adj[u].pb(mp(v,-w));
        edge.pb(mp(mp(u,v),-w));
        rev[v].pb(u);
    }

    //dfs(n,0);
    listbad();
    if(negcycle()) bad =   true;

    if(bad) cout<<"inf\n";
    else{
        cout<<-dist[n]<<newl;
    }

}
