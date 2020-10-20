#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
vector<pair<int,int> >adj[2600];
int v,e,a,b,dist[2600];
bool vis[2600];
priority_queue < pair<int,int> > m;
void dijkstra(){
    for(int i=1;i<=v;i++)dist[i]=3000;
    dist[a]=0;
    m.push(make_pair(0,a));
    while(!m.empty()){
        int t = m.top().second;
        m.pop();
        if(!vis[t]){
            vis[t]=true;
            for(int i=0;i<adj[t].size();i++){
                int temp = adj[t].at(i).first;
                int tempw = adj[t].at(i).second;
                if(dist[temp] > dist[t] + tempw){
                    dist[temp] = dist[t] + tempw;
                    m.push(make_pair(dist[temp]*-1,temp));
                }
            }
        }
    }
}
int main(){
    cin>>v>>e>>a>>b;
    for(int i=1;i<=e;i++){
        int x,y,z;cin>>x>>y>>z;
        adj[x].push_back(make_pair(y,z));
        adj[y].push_back(make_pair(x,z));
    }
    dijkstra();
    cout<<dist[b]<<endl;
}
