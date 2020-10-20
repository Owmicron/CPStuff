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
int n,deg[10000],laz[10000],now;
vi adj[10000];
bool vis[10000];
void bfs(int source, int stop){
    queue <int> q;
    q.push(source);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(!vis[node] && node!=stop){
            laz[node] = 1;
            now--;
            vis[node] = true;
            for(int i=0;i<adj[node].size();++i) q.push(adj[node][i]);
        }
    }
}
void relax(){

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            for(int j=0;j<adj[i].size();j++){
                int nex = adj[i][j];
                if(laz[nex] > 0){deg[i]--;laz[nex] = 0;}
            }
        }
    }
}
void query(){
    vi temp;
    for(int i=1;i<=n;i++){
        if(!vis[i] && deg[i] == 1) temp.pb(i);
        if(temp.size()>=2) break;
    }

    int u = temp[0];
    int v = temp[1];
    cout<<"? "<<u<<" "<<v<<newl;
    fflush(stdout);
    int lca;
    cin>>lca;
    bfs(u,lca);
    bfs(v,lca);
    relax();

}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    cin>>n;
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
        deg[u] ++;
        deg[v] ++;
    }

    now = n;
    int quer = 0;
    while(now > 1){
        quer ++;
        int f = n/2;
        if(quer > f){break;}
        query();
    }

    int ans = 0;
    for(int i=1;i<=n;i++) if(!vis[i]) {ans = i; break;}
    cout<<"! "<<ans<<newl;
    fflush(stdout);
}
