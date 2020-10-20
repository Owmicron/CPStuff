#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,m;
vector<int> adj[300000];
vector< pair<int,int> > ans;
priority_queue <int> q;
bool vis[300000];
bool relaxed[300000];
void tree(int x){
    q.push(x);
    relaxed[x]=true;
    while(!q.empty()){
        int t = q.top();
        q.pop();
        if(!vis[t]){
            vis[t]=true;
            for(int i=0;i<adj[t].size();i++){
                if(!relaxed[adj[t].at(i)] && !vis[adj[t].at(i)]){
                    ans.push_back (make_pair(t,adj[t].at(i)));
                    relaxed[adj[t].at(i)] = true;
                    q.push(adj[t].at(i));
                }
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int mx=-1;int idx=-1;
    //cout<<endl;
    for(int i=1;i<=n;i++){
        //cout<<i<<" "<<adj[i].size()<<endl;
        //cout<<mx<<endl;
        int temp=adj[i].size();
        if(temp>mx){mx=temp;idx=i;}
    }
    tree(idx);
    for(int i=0;i<ans.size();i++){
        cout<<ans.at(i).first<<" "<<ans.at(i).second<<endl;
    }
}




