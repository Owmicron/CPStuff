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
int n,A,T;
vi adj[100010];
ll dist[100010];
bool vd[100010];
void dijkstra(){
    for(int i=1;i<=n;i++) dist[i] = INT_MAX;
    for(int i=1;i<=n;i++) vd[i] = false;
    priority_queue < pii > q;
    q.push(mp(0,T));
    dist[T] = 0;
    while(!q.empty()){
        int node = q.top().se;
        q.pop();
        if(!vd[node]){
            vd[node] = true;
            for(int i=0;i<adj[node].size();i++){
                int nex = adj[node][i];
                if(dist[nex] > dist[node] + 1){
                    dist[nex] = dist[node] + 1;
                    q.push(mp(-dist[nex],nex));
                }
            }
        }
    }
}
bool eaten(int x){
    bool vis[n+10];
    for(int i=1;i<=n;i++) vis[i] = false;
    queue <pii> q;
    q.push(mp(0,A));
    while(!q.empty()){
        int node = q.front().se;
        int steps = q.front().fi;
        q.pop();
        if(steps>x) break;
        if(!vis[node]){
            vis[node] = true;
            for(int i=0;i<adj[node].size();i++){
                q.push(mp(steps+1,adj[node][i]));
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(dist[i]%2 == x%2 && dist[i]<=x){
            bool danger = true;
            if(!vis[i]){
                for(int j=0;j<adj[i].size();j++){
                    if(!vis[adj[i][j]]) {danger = false; break;}
                }
            }

            if(!danger) return false;
        }
    }
    return true;
}
int bins(){
    int l = 0;
    int r = n;
    int res = 0;
    while(l<=r){
        int mid = (l+r)/2;
        if(eaten(mid)){res = mid;r = mid-1;}
        else{l = mid+1;}
    }
    return res;
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>T>>A;
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dijkstra();

    cout<<bins()<<newl;
//    cout<<newl;
//    for(int i=0;i<=n;i++) cout<<i<<" "<<eaten(i)<<newl;
}

