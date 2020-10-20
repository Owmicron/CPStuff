#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int,int> vii;
typedef vector<ll,ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;
typedef map <str,int> mapsi;
typedef map <str,int> :: iterator mapsitr;
typedef set <int> :: iterator sitr;
typedef set <ll> :: iterator sltr;
#define mset multiset
typedef mset <int> msi;
typedef mset <ll> msll;
typedef mset <int> :: iterator msitr;
typedef mset <ll> :: iterator msltr;
#define mp make_pair
#define pb push_back
#define pob pop_back
#define fi first
#define se second
#define fs first.second
#define ss second.second
#define ff first.first
#define sf second.first
vpll adj[200000];
int n;
bool black [200000];
bool vis[200000];
void color (){
    queue <ll> q;
    black[1] = true;
    q.push(1);

    while(!q.empty()){
        ll node = q.front();
        q.pop();
        if(!vis[node]){
            vis[node]=true;
            for(int i=0;i<adj[node].size();i++){
                ll nex,l;
                nex = adj[node][i].fi;
                l = adj[node][i].se;
                if(!vis[nex]){
                    if(l%2==0){
                        black[nex] = black[node];
                    }
                    else{
                        black[nex] = not black[node];
                    }
                    q.push(nex);
                }
            }
        }
    }

}
int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        ll v1,v2,w;
        cin>>v1>>v2>>w;
        adj[v1].pb(mp(v2,w));
        adj[v2].pb(mp(v1,w));
    }
    color();
    for(int i=1;i<=n;i++){
        cout<<black[i]<<endl;
    }
}
