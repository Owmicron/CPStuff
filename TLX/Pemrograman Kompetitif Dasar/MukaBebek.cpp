#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int INF = 1000000000;
int n,w[103][103],dist[103];
vector<int> adj[103];
bool vis[103];
priority_queue <pair<int , int> > q;
int prim(int x){
    int cost=0;
    for(int i=1;i<=n;i++)dist[i]=INF;
    q.push(make_pair(0,x));
    dist[x]=0;
    while(!q.empty()){
        int u = q.top().second;
        q.pop();
        if(!vis[u]){
            vis[u]=true;
            cost+=dist[u];
            for(int i=0;i<adj[u].size();i++){
                int v = adj[u].at(i);
                if((!vis[v]) && (dist[v] > w[u][v])){
                    dist[v] = w[u][v];
                    q.push(make_pair(dist[v]*-1 , v));
                }
            }
        }
    }
    return cost;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>w[i][j];
            if(i!=j){adj[i].push_back(j);}
        }
    }
//    for(int i=1;i<=n;i++){
//        cout<<i<<" = ";
//        for(int j=0;j<adj[i].size();j++){
//            cout<<adj[i].at(j)<<" ";
//        }cout<<endl;
//    }
    cout<<prim(1)<<endl;
}
