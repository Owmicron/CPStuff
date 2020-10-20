#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,l,t,city,rome,d[1000],dr[1000],ans;
queue <int> q;
vector <int> adj [1000];
pair <int, int> tol[200000];
bool visited[1000],cityside[1000],romeside[1000];
int main(){
    cin>>n>>l>>t>>city>>rome;
    for(int i=1;i<=l;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);adj[b].push_back(a);
    }
    for(int i=1;i<=t;i++){
        int a,b;cin>>a>>b;
        tol[i]=make_pair(a,b);
    }
    //bfs
    visited[city]=true;
    q.push(city);
    while(!q.empty()){
        int x; x = q.front();
        q.pop();
        for(int i=0;i<adj[x].size();i++){
            if(!visited[adj[x].at(i)]){
                visited[adj[x].at(i)]=true;
                d[adj[x].at(i)]=d[x]+1;
                q.push(adj[x].at(i));
            }
        }
    }

    if(d[rome]>0){

        for(int i=1;i<=n;i++)visited[i]=false;
        visited[rome]=true;
        q.push(rome);
        while(!q.empty()){
            int x; x = q.front();
            q.pop();
            for(int i=0;i<adj[x].size();i++){
            if(!visited[adj[x].at(i)]){
                visited[adj[x].at(i)]=true;
                dr[adj[x].at(i)]=dr[x]+1;
                q.push(adj[x].at(i));
            }
        }
        }
        int mn = d[rome];

        for(int i=1;i<=t;i++){
            if((!visited[tol[i].first])||(!visited[tol[i].second])){continue;}
            int a = d[tol[i].first];
            int b = d[tol[i].second];
            int temp = 0;
            temp = min( a + dr[tol[i].second]+1 , b + dr[tol[i].first]+1 );
            mn = min(mn,temp);
        }
        ans = mn;
    }

    else{
        for(int i=1;i<=n;i++){
            if(d[i]>0){cityside[i]=true;}
        }
        cityside[city]=true;
        visited[rome]=true;
        q.push(rome);
        romeside[rome]=true;
        while(!q.empty()){
            int x; x = q.front();
            q.pop();
            for (int i=0;i<adj[x].size();i++){
                if(!visited[adj[x].at(i)]){
                    visited[adj[x].at(i)]=true;
                    romeside[adj[x].at(i)]=true;
                    d[adj[x].at(i)] = d[x]+1;
                    q.push(adj[x].at(i));
                }
            }
        }
        int mn=1000000;
        for(int i=1;i<=t;i++){
            int a = tol[i].first;
            int b = tol[i].second;
            int temp;
            if(cityside[a]){
                if(romeside[b]){
                    temp = d[a]+d[b]+1;
                    mn = min(temp,mn);
                }
            }
            if(romeside[a]){
                if(cityside[b]){
                    temp = d[a]+d[b]+1;
                    mn = min(temp,mn);
                }
            }
        }
        if(mn==1000000){mn=0;}
        ans = mn;
    }
    if(city==rome){ans=0;}
    cout<<ans<<endl;
}
