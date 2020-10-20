#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int T,v,e,dist[550];
pair < pair<int,int> , int > edge[1100];
vector< int > adj[550];
bool vis[550];
void bellman_ford(int x){
    for(int i=0;i<v;i++){
        dist[i]=50000000;
    }
    dist[x]=0;
    for(int i=1;i<=v-1;i++){
        for(int j=1;j<=e;j++){
            int x,y,w;
            x = edge[j].first.first;
            y = edge[j].first.second;
            w = edge[j].second;
            if(dist[y] > dist[x] + w){
                dist[y] = dist[x]+w;
            }
        }
    }
}
bool has_ncycle(){
    bool pos = true;

    for(int i=1;i<=e;i++){
        int x,y,w;
        x = edge[i].first.first;
        y = edge[i].first.second;
        w = edge[i].second;
        if(dist[y] > dist[x] + w){
            pos = false;
        }
    }
    pos = not pos;
    return pos;
}

void bfs(int x){
    for(int i=0;i<v;i++){
        vis[i]=false;
    }
    vis[x]=true;
    queue <int> q;
    q.push(x);

    while(!q.empty()){
        int t = q.front();
        q.pop();

        for(int i=0;i<adj[t].size();i++){
            if(!vis[adj[t].at(i)]){
                vis[adj[t].at(i)]=true;
                q.push(adj[t].at(i));
            }
        }
    }
    for(int i=1;i<=e;i++){
        if ((vis[edge[i].first.first]) && (vis[edge[i].first.second])){continue;}
        else{
            edge[i] = make_pair(make_pair(0,0),0);
        }
    }
}
int main(){
    cin>>T;
    for(int cases=1;cases<=T;cases++){
        cin>>v>>e;
        for(int i=1;i<=e;i++){
            int a,b,c;cin>>a>>b>>c;
            if(a==v-1){a=0;b=0;c=0;}
            adj[a].push_back(b);
            edge[i]=(make_pair(make_pair(a,b),c));
        }

        bfs(0);
        bellman_ford(0);

        if(has_ncycle()){
            cout<<"Pak Dengklek tidak mau pulang"<<endl;
        }
        else{
            if(dist[v-1] == 50000000){cout<<"Tidak ada jalan"<<endl;}
            else{cout<<dist[v-1]<<endl;}
        }
    }
}
