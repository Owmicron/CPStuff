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

int k;
vpii adj[100010];
bool vis[100010];
ll dist[100010];
void dijkstra(){
    for(int i=0;i<k;i++)dist[i]=INT_MAX;
    priority_queue < pii > q;
    q.push(mp(0,1));
    dist[1] = 0;
    while(!q.empty()){
        int node = q.top().se;
        q.pop();
        if(!vis[node]){
            vis[node]=true;
            for(int i=0;i<adj[node].size();i++){
                int nex = adj[node][i].fi;
                int w = adj[node][i].se;
                if(dist[nex] > dist[node] + w){
                    dist[nex] = dist[node] + w;
                    q.push(mp(-dist[nex],nex));
                }
            }

        }

    }
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    cin>>k;
    for(int i=0;i<k;i++){
        adj[i].pb(mp((i+1)%k,1));
        adj[i].pb(mp((i*10)%k,0));
    }
    dijkstra();
    cout<<dist[0]+1<<newl;

}
