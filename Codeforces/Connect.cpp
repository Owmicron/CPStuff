#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,r1,c1,r2,c2,ans;
char planet[60][60];
bool vis[60][60],vist[60][60];
int dist (int rs, int cs, int rt, int ct){
    int temp;
    temp = (rs-rt)*(rs-rt) + (cs-ct)*(cs-ct);
    return temp;
}
vector <pair<int,int> > start,fin;
bool visitable(int y, int x){
    if(y<1 || y>n || x<1 || x>n || planet[y][x]=='1' || vis[y][x]){return false;}
    return true;
}
bool visitablet(int y, int x){
    if(y<1 || y>n || x<1 || x>n || planet[y][x]=='1' || vist[y][x]){return false;}
    return true;
}
void bfs(){
    queue < pair<int,int> > q;
    q.push(make_pair(r1,c1));

    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        if(!vis[y][x]){
            vis[y][x]=true;
            if(visitable(y+1,x)){q.push(make_pair(y+1,x));}
            if(visitable(y-1,x)){q.push(make_pair(y-1,x));}
            if(visitable(y,x+1)){q.push(make_pair(y,x+1));}
            if(visitable(y,x-1)){q.push(make_pair(y,x-1));}
        }
    }
}
void bfs2(){
    queue < pair<int,int> > q;
    q.push(make_pair(r2,c2));

    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        if(!vist[y][x]){
            vist[y][x]=true;
            if(visitablet(y+1,x)){q.push(make_pair(y+1,x));}
            if(visitablet(y-1,x)){q.push(make_pair(y-1,x));}
            if(visitablet(y,x+1)){q.push(make_pair(y,x+1));}
            if(visitablet(y,x-1)){q.push(make_pair(y,x-1));}
        }
    }
}
int main(){
    scanf("%d",&n);
    scanf("%d %d",&r1,&c1);
    scanf("%d %d",&r2,&c2);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>planet[i][j];
        }
    }

    bfs();
    if(vis[r2][c2]){ans=0;}
    else{
        bfs2();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(vis[i][j]){
                    start.push_back(make_pair(i,j));
                }
                else if(vist[i][j]){
                    fin.push_back(make_pair(i,j));
                }
            }
        }
        ans=INT_MAX;
        for(int i=0;i<start.size();i++){
            for(int j=0;j<fin.size();j++){
                int t;
                t = dist (start[i].first,start[i].second,fin[j].first,fin[j].second);
                ans = min(ans,t);
            }
        }
    }
    cout<<ans;
}
