#include<bits/stdc++.h>

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
    if( 97 <= int(x) && int(x) <= 126)return char(x-32);
    else if( 65 <= int(x) && int(x) <= 90)return x;
}
char to_lower (char x){
    if( 97 <= int(x) && int(x) <= 126)return x;
    else if( 65 <= int(x) && int(x) <= 90)return char(x+32);
}
int numerize (char x){
    if(48 <= int(x) && int(x) <= 57)return int(x-'0');
    else if( 97 <= int(x) && int(x) <= 126)return int(x-96);
    else if( 65 <= int(x) && int(x) <= 90)return int(x-64);
}
bool isect (int l1, int r1, int l2, int r2){
    pii p1,p2;
    p1 = mp(l1,r1); p2 = mp(l2,r2);
    if(p1>p2)swap(p1,p2);
    if(p2.fi <= p1.se)return true;
    else return false;
}
ll fexp (ll num1, ll num2, ll MOD){
    if(num2==0)return 1;
    else if(num2==1)return num1;
    else{
        ll temp = fexp (num1,num2/2,MOD); ll res = ((temp%MOD) * (temp%MOD))%MOD;
        if(num2%2==1) res = ((res%MOD)*(num1%MOD))%MOD; return res;
    }
}
ll invmod (ll num, ll MOD){return fexp (num,MOD-2,MOD);}
ll gcd (ll num1, ll num2){
    if(num1 < num2) swap(num1,num2); ll num3 = num1 % num2 ;
    while(num3 > 0){ num1 = num2; num2 = num3; num3 = num1 % num2;}
    return num2;
}
ll lcm (ll num1 , ll num2){return (ll) (num1/gcd(num1,num2))*num2;}
// end of Template
int n;
pair <pii,int> byx[100010],byy[100010];
map <pii,int> m;
map <pii,int> :: iterator itr;
vector < pii > adj[100010];
ll INF = 1e12;
ll dist[100010];
bool vis[100010];
ll prim (){
    ll cost = 0;
    for(int i=1;i<=n;i++)dist[i]=INF;
    priority_queue < pll > q;
    q.push(mp(0,1)); dist[1] = 0;
    while(!q.empty()){
        int node = q.top().se;
        ll curd = q.top().fi;
        q.pop();
        if(!vis[node]){
            vis[node] = true;
            cost += dist[node];
            for(int i=0;i<adj[node].size();i++){
                int nex = adj[node][i].se;
                ll w = adj[node][i].fi;

                if((dist[nex] >  w) && (!vis[nex])){
                    dist[nex] = w;
                    q.push(mp(-dist[nex],nex));
                }
            }
        }
    }
    return cost;
}
map < pii , bool > paint;
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y; cin>>x>>y;
        byx[i] = mp(mp(x,y),i);
        byy[i] = mp(mp(y,x),i);
    }
    sort(byx+1,byx+1+n);
    sort(byy+1,byy+1+n);

    for(int i=2;i<=n;i++){
        pii ed = mp(byx[i-1].se , byx[i].se);
        if(ed.fi > ed.se)swap(ed.fi,ed.se);
        int w = byx[i].ff - byx[i-1].ff;
        if(!paint[ed]){m[ed]=w;paint[ed]=true;}
        else{m[ed]=min(m[ed],w);}
    }

    for(int i=2;i<=n;i++){
        pii ed = mp(byy[i-1].se , byy[i].se);
        if(ed.fi > ed.se)swap(ed.fi,ed.se);
        int w = byy[i].ff - byy[i-1].ff;
        if(!paint[ed]){m[ed]=w;paint[ed]=true;}
        else{m[ed]=min(m[ed],w);}
    }

    for(itr = m.begin(); itr!=m.end(); itr++){
        pii p = itr->fi;
        int w = itr->se;
        adj[p.fi].pb(mp(w,p.se));
        adj[p.se].pb(mp(w,p.fi));
    }
    cout<<prim()<<newl;


}
