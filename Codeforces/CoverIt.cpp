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
//void IO(){
//	#ifndef ONLINE_JUDGE
//	    freopen("input.txt", "r", stdin);
//	    freopen("output.txt", "w", stdout);
//	#endif
//}
// end of Template

int t,n,m,u[200010],v[200010];
vi adj[200010];
void solve(){
    bool vis[200010];
    int value[200010];
    vi a,b;
    queue<int> q;
    q.push(1);
    for(int i=1;i<=n;i++)vis[i]=false;
    for(int i=1;i<=n;i++)value[i]=0;
    value[1] = 1;

    int mov = 0;
    while(!q.empty()){
        int node = q.front();
        mov ++;
        q.pop();
        if(!vis[node]){
            vis[node]=true;
            for(int i=0;i<adj[node].size();i++){
                int nex = adj[node][i];
                if(value[nex]==0){
                    if(mov%2==0){
                        value[nex] = 1;
                    }
                    else{
                        value [nex] = 2;
                    }
                    q.push(nex);
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(value[i]==1){a.pb(i);}
        else b.pb(i);
    }
    if(a.size()<=b.size()){
        cout<<a.size()<<newl;
        for(int i=0;i<a.size();i++)cout<<a[i]<<" ";
        cout<<newl;
    }
    else{
        cout<<b.size()<<newl;
        for(int i=0;i<b.size();i++)cout<<b[i]<<" ";
        cout<<newl;
    }

}
pii node[200010];
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    for(int cases=1;cases<=t;cases++){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            node[i] = mp (0,i);
        }

        bool vis[200010];
        for(int i=1;i<=n;i++)vis[i]=false;

        for(int i=1;i<=m;i++){
            cin>>u[i]>>v[i];
            adj[u[i]].pb(v[i]);
            adj[v[i]].pb(u[i]);

            node[u[i]].fi++;
            node[v[i]].fi++;
        }
        sort(node+1,node+1+n);
        vi ans;
        for(int i=n;i>=1;i--){
            int idx = node[i].se;

            if(!vis[idx]){
                vis[idx]=true;
                ans.pb(idx);
                for(int j=0;j<adj[idx].size();j++){
                    vis[adj[idx][j]] = true;
                }
            }
        }

        cout<<ans.size()<<newl;
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";cout<<newl;
        for(int i=1;i<=n;i++){
            while(!adj[i].empty())adj[i].pob();
        }
    }
}
