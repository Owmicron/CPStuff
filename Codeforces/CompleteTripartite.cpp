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
int type[100010];
int n,m;
vi adj[100010];
vpii edges;
bool valid = true;
bool vis[100010];

void component(int node, int start){
    queue <pii> q;
    q.push(mp(node,0));
    vi v;
    while(!q.empty()){
        int x = q.front().fi;
        int steps = q.front().se;
        q.pop();
        if(!vis[x]){
            vis[x] = true;
            int tmp = steps%3;
            tmp = start + tmp;
            if(tmp>3)tmp-=3;
            type[x]=tmp;

            v.pb(x);
            for(int i=0;i<adj[x].size();i++){
                q.push(mp(adj[x][i],steps+1));
            }
        }
    }
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
        edges.pb(mp(u,v));
    }

    int com = 3;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            com ++;
            if(com>3) com=1;
            component(i,com);
        }
    }


    bool a,b,c,d,e,f;
    d = false;
    e = false;
    f = false;
    for(int i=0;i<edges.size();i++){
        int u = edges[i].fi;
        int v = edges[i].se;
        int tu = type[u];
        int tv = type[v];
        if(tu==tv){valid=false;break;}

        if(tu>tv)swap(tu,tv);

        if(tu==1 && tv==2){d = true;}
        if(tu==1 && tv==3){e = true;}
        if(tu==2 && tv==3){f = true;}
    }

    if(valid){
        if(d&&e&&f){}
        else valid=false;
    }

    if(!valid)cout<<-1<<newl;
    else{
        for(int i=1;i<=n;i++)cout<<type[i]<<" ";
    }
}
