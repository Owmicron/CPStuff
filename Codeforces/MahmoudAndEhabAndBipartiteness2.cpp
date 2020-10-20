#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
vector<int> adj[200000];
bool vis[200000];
int group [200000];
int n;
queue <int> q;
void bfs(){
    group[1]=1;
    q.push(1);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        if(!vis[node]){
            vis[node]=true;
            for(int i=0;i<adj[node].size();i++){
                if(group[node]==1) group[adj[node].at(i)]=2;
                else if(group[node]==2) group[adj[node].at(i)]=1;
                q.push(adj[node].at(i));
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs();
    ll a=0; ll b=0;
    for(int i=1;i<=n;i++){
        if(group[i]==1){a++;}
        else if(group[i]==2){b++;}
    }
    ll ans=0;
    ans = a*b;ans-= (n-1);
    printf("%lld\n",ans);
}
