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
// end of Template

int n,k,dmax;
vi adj[100010];
int v[100010],f[100010];
bool vis[100010];
ll ans = 1;
ll md = 1e9+7;
vll mul;
void bfs(){
    queue <int> q;
    q.push(1);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(!vis[node]){
            vis[node]=true;

            ll m = k-2;
            if(node==1)m++;

            for(int i=0;i<adj[node].size();i++){
                int nex = adj[node][i];
                if(!vis[nex]){
                    mul.pb(m);
                    q.push(nex);
                    m--;
                }
            }
        }
    }

}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bfs();

    mul.pb(k);
//    for(int i=2;i<=dmax;i++){
////        cout<<i<<" "<<f[i]<<newl;
//        v[i] = v[i-1] - 1;
//        if(i>3){v[i] += f[i-3];}
//
//        for(int j=1;j<=f[i];j++){
//            int ft = j-1;
//            ll temp = v[i]-ft;
//            temp = max(temp,(ll)0);
//            mul.pb(v[i]-ft);
//        }
//    }

    for(int i=0;i<mul.size();i++){
//        cout<<i<<" "<<mul[i]<<newl;
        ans = ((ans%md)*(mul[i]%md))%md;
    }
    cout<<ans<<newl;
}

