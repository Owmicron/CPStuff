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
int n;
pair <int , pii > tup [200000];
vi adj[200000],isi[200000];
int diff(int x, int y){
    vi a,b;
    a.pb(tup[x].fi);a.pb(tup[x].sf);a.pb(tup[x].ss);
    b.pb(tup[y].fi);b.pb(tup[y].sf);b.pb(tup[y].ss);

    int res = 0;
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            if(a[i] == b[j]) res++;
        }
    }
    return res;
}
pii sam (int x, int y){
    vi a,b;
    a.pb(tup[x].fi);a.pb(tup[x].sf);a.pb(tup[x].ss);
    b.pb(tup[y].fi);b.pb(tup[y].sf);b.pb(tup[y].ss);

    vi z;
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            if(a[i] == b[j]) z.pb(a[i]);
        }
    }
    return mp(z[0],z[1]);
}
map < pii , bool > jnn;
void check(int x){
    for(int i=0;i<isi[x].size();i++){
        for(int j=i+1;j<isi[x].size();j++){
            if(i==j) continue;
            if(diff(isi[x][i],isi[x][j]) == 2 ){
                int a = isi[x][i];
                int b = isi[x][j];
                if(!jnn[mp(a,b)]){
                    jnn[mp(a,b)] = true;
                    adj[a].pb(b);
                    adj[b].pb(a);
                }
                //cout<<x<<" "<<a<<" "<<b<<newl;
            }
        }
    }
}
bool vis[200010];
vi seq;
vpii pro;
void bfs(int x){
    queue <int> q;
    q.push(x);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(!vis[node]){
            vis[node] = true;
            seq.pb(node);
            for(int i=0;i<adj[node].size();i++) q.push(adj[node][i]);
        }
    }
}
vi ans;
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=1;i<=n-2;i++){
        int z[4];
        cin>>z[1]>>z[2]>>z[3];
        for(int j=1;j<=3;j++) isi[z[j]].pb(i);
        sort(z+1,z+4);
        tup[i] = mp(z[1] , mp(z[2],z[3]));

    }

    for(int i=1;i<=n;i++){
        sort(isi[i].begin(),isi[i].end());
        //cout<<i<<" : ";for(int j=0;j<isi[i].size();j++) cout<<isi[i][j]<<" ";cout<<newl;
        check(i);
    }

    for(int i=1;i<=n-2;i++){
        if(adj[i].size()==1){
            bfs(i);break;
        }
    }

    for(int i=1;i<seq.size();i++){
        pro.pb(sam(seq[i],seq[i-1]));
    }
    //  for(int i=0;i<pro.size();i++) cout<<" --- "<<pro[i].fi<<" "<<pro[i].se<<newl;
    if(pro[0].se == pro[1].fi || pro[0].se == pro[1].se){}
    else swap(pro[0].fi , pro[0].se);


    for(int i=1;i<pro.size();i++){
        if(pro[i].fi != pro[i-1].se) swap(pro[i].fi,pro[i].se);
    }

    if( isi[ tup [seq[0]].fi ] . size() == 1){ans.pb(tup [seq[0]].fi) ;}
    else if ( isi[ tup [seq[0]].sf ] . size() == 1){ans.pb(tup [seq[0]].sf);}
    else if ( isi[ tup [seq[0]].ss ] . size() == 1){ans.pb(tup [seq[0]].ss);}

    for(int i=0;i<pro.size();i++) ans.pb(pro[i].fi);
    ans.pb(pro.back().se);

    if( isi[ tup [seq.back()].fi ] . size() == 1){ans.pb(tup [seq.back()].fi) ;}
    else if ( isi[ tup [seq.back()].sf ] . size() == 1){ans.pb(tup [seq.back()].sf);}
    else if ( isi[ tup [seq.back()].ss ] . size() == 1){ans.pb(tup [seq.back()].ss);}

    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
}
