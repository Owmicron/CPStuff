#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int T,n,e,q,r,p[50100],special,sum;
pair<int, int>ab[200010];
vector<int> adj[50100];
int graph[50010],g;
bool invalid[200010],spec[50100],visited[50100];
void dfs(int x){
    visited[x]=true;
    if(spec[x]){special++;}
    stack <int> node;
    if(!adj[x].empty()){
        while(!adj[x].empty()){
            node.push(adj[x].back());
            adj[x].pop_back();
        }
    }
    while(!node.empty()){
        if(!visited[node.top()]){
            dfs(node.top());
        }
        node.pop();
    }
}
int main(){
    cin>>T;
    for(int cases=1; cases<=T; cases++){
        cin>>n>>e>>q>>r;
        for(int i=1;i<=e;i++){
            int a,b;
            cin>>a>>b;
            ab[i]=make_pair(a,b);
        }
        for(int i=1;i<=q;i++){
            cin>>p[i];spec[p[i]]=true;
        }
        for(int i=1;i<=r;i++){
            int t;cin>>t;
            invalid[t]=true;
        }
        //make adjacency list
        for(int i=1;i<=e;i++){
            if(!invalid[i]){
                adj[ab[i].first].push_back(ab[i].second);
                adj[ab[i].second].push_back(ab[i].first);
            }
        }
        //dfs

        g=0;sum=0;
        for(int i=1;i<=q;i++){
            special=0;
            if(!visited[p[i]]){
                dfs(p[i]);
                g++;graph[g]=special;sum+=graph[g];
            }
        }
        int ans=0;
        for(int i=1;i<=g;i++){
            sum-=graph[i];
            ans+= graph[i] * sum;
        }
        cout<<ans<<endl;
        for(int i=1;i<=e;i++)invalid[i]=false;
        for(int i=1;i<=q;i++)spec[p[i]]=false;
        for(int i=1;i<=n;i++)visited[i]=false;
        for(int i=1;i<=n;i++){
            while(!adj[i].empty())adj[i].pop_back();
        }
    }
}
