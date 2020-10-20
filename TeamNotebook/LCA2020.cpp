#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(),x.rend()
#define watch(x) cout << (#x) << " is : " << (x) << newl

int n,parent[20][100010],depth[100010];
bool vis[100010];
vi adj[100010];
void build_parent(){
    queue <int> q;
    q.push(1);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(!vis[node]) {
            vis[node] = true;
            for(auto i : adj[node]){
                if(!vis[i]){
                    parent[0][i] = node;
                    q.push(i);
                }
            }
        }
    }

    for(int i = 1; i <= log(n)/log(2); ++i){
        for(int j = 1; j <= n; ++j){
            parent[i][j] = parent[i-1][parent[i-1][j]];
        }
    }
}
void build_depth(){
    queue <pii> q;
    q.push({1,1});
    memset(vis,false,sizeof(vis));
    while(!q.empty()){
        int node = q.front().fi;
        int dist = q.front().se;
        q.pop();
        if(!vis[node]){
            vis[node] = true;
            depth[node] = dist;
            for(auto i : adj[node]) if(!vis[i]) q.push({i,dist+1});
        }
    }
}
pii lift(pii p, int maxn){
    int a = p.fi;
    int b = p.se;
    for(int i = maxn; i >= 0; --i){
        if(parent[i][a] != parent[i][b]){
            a = parent[i][a];
            b = parent[i][b];
            return lift({a,b},i);
        }
    }
    return p;
}
int lca(int a, int b){
    if(depth[a] > depth[b]) swap(a,b);

    if(depth[a] != depth[b]){
        int dist = abs(depth[a] - depth[b]);
        for(int i = 0; i < 20; ++i) if(dist & (1<<i)) b = parent[i][b];
    }

    int ans = a;
    if(a != b){
        pii res = lift({a,b},20);
        ans = parent[0][res.fi];
    }
    return ans;
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // input TREE
    cin >> n;
    for(int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    build_parent();
    build_depth();

    cout<<lca(5,6);
}
