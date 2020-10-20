#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
vector<int> adj[300000];
bool vis[300000];
int n,m,role[300000];
int u[300000],v[300000];
str s;
bool valid;
queue<int> q;
void bfs(){
    role[1]=1;
    q.push(1);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        if(!vis[node]){
            vis[node]=true;
            for(int i=0;i<adj[node].size();i++){
                if(!vis[adj[node][i]]){
                    int r;
                    if(role[node]==1){r=2;}
                    else if(role[node]==2){r=1;}
                    role[adj[node][i]]=r;
                    q.push(adj[node][i]);
                }
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i];
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
    }
    bfs();
    valid=true;
    for(int i=1;i<=m;i++){
        if(role[u[i]]==role[v[i]]){valid=false;break;}
        if(role[u[i]]==1){s+="1";}
        else{s+="0";}
    }
    if(valid){cout<<"YES"<<endl<<s<<endl;}
    else{cout<<"NO\n";}
}

