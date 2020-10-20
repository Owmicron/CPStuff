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
#define watch(x) cout << (#x) << " is : " << (x) << newl

char to_upper (char x){
    if( 97 <= int(x) && int(x) <= 122) return char(x-32);
    if( 65 <= int(x) && int(x) <= 90) return x;
    return -1;
}
char to_lower (char x){
    if( 97 <= int(x) && int(x) <= 122) return x;
    if( 65 <= int(x) && int(x) <= 90) return char(x+32);
    return -1;
}
int numerize (char x){
    if(48 <= int(x) && int(x) <= 57) return int(x-'0');
    if( 97 <= int(x) && int(x) <= 122) return int(x-96);
    if( 65 <= int(x) && int(x) <= 90) return int(x-64);
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
    if(num2==0)return 1%MOD;
    else if(num2==1)return num1%MOD;
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
int t,n,m,stat,lab,ans1,ans2;
int color[1000010],nex[1000010],vis[1000010];
pii id[1000010];
bool cycle[1000010];
vi cyc[1000010],pre[1000010];
int trans (int r, int c){
    return (r-1)*m + c;
}
void dfs(int node){
    if(vis[node] == 0){
        vis[node] = 1;
        dfs(nex[node]);
        if(stat){
            cyc[lab].pb(color[node]);
            cycle[node] = true;
            ans1++;
            id[node] = mp(lab, cyc[lab].size()-1);
            //index[node] = cyc[lab].size()-1;
            if(color[node] == 0) ans2++;
        }
        else cycle[node] = false;

        if(node == stat) stat = 0;
        vis[node] = 2;
    }
    else if(vis[node] == 1){
        stat = node;
        lab++; cycle[node] = true;
    }
}
void solve(){
    lab = 0;
    cin>>n>>m;
    ans1 = 0;
    ans2 = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cyc[trans(i,j)].clear();
            vis[trans(i,j)] = false;
            id[trans(i,j)] = mp(0,0);
            pre[trans(i,j)].clear();
            nex[trans(i,j)] = 0;
            char COLOR; cin>>COLOR;
            color[trans(i,j)] = numerize(COLOR);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char dir; cin>>dir;
            if(dir == 'R') nex[trans(i,j)] = trans(i,j+1), pre[trans(i,j+1)].pb(trans(i,j));
            if(dir == 'L') nex[trans(i,j)] = trans(i,j-1), pre[trans(i,j-1)].pb(trans(i,j));
            if(dir == 'U') nex[trans(i,j)] = trans(i-1,j), pre[trans(i-1,j)].pb(trans(i,j));
            if(dir == 'D') nex[trans(i,j)] = trans(i+1,j), pre[trans(i+1,j)].pb(trans(i,j));
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dfs(trans(i,j));
        }
    }

//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=m;j++){
//            cout<<"("<<cycle[trans(i,j)]<<",("<<id[trans(i,j)].fi<<" "<<id[trans(i,j)].se<<")) ";
//        }cout<<newl;
//    }

    // (lab,idx) , (dist,node)
    queue < pair < pii , pii > > q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int h = trans(i,j);
            if(cycle[h]) q.push (mp(id[h],mp(0,h)));
        }
    }

    vector < pair < pii , pii> > v;
    while(!q.empty()){
        int dist = q.front().sf;
        int node = q.front().ss;

        for(int i=0;i<pre[node].size();i++){
            int p = pre[node][i];
            if(!cycle[p]){
                v.pb(mp(q.front().fi,mp(dist+1,p)));
                q.push(mp(q.front().fi,mp(dist+1,p)));
            }
        }
        q.pop();
    }

//    cout<<newl;
//    for(int i=1;i<=lab;i++){
//        cout<<"cycle "<<i<<" : ";
//        for(int j=0;j<cyc[i].size();j++) cout<<cyc[i][j]<<" ";cout<<newl;
//    }

    for(int i=0;i<v.size();i++){
        int dist = v[i].sf;
        int label = v[i].ff;
        int idx = v[i].fs;
        int node = v[i].ss;
//        cout<<dist<<" : ( "<<label<<" - "<<idx<<" ) "<<node<<newl;
        if(color[node] == 1) continue;
        int dest = (dist + idx) % (int) cyc[label].size();
        if(cyc[label][dest] == 1){
            ans2++;
            cyc[label][dest] = 0;
        }
    }
    cout<<ans1<<" "<<ans2<<newl;
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
