#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int INF = 10000000;
int r,c,n,node[1001][1001],start,finish,ra,ca,rb,cb,w[1001][1001];
bool vis[1002][1002],got;
priority_queue <pair < int, pair<int, int> > >q;
bool visitable (int y, int x){
    if(y==0 || y>r || x==0 || x>c || node[y][x] == -1)return false;
    return true;
}
void relax (int y, int x){
//    for(int i=0;i<adj[vtx].size();i++){
//        int idx = adj[vtx].at(i);
//        if(!vis[idx]){
//            w[ idx ] = min (w[idx] , max(w[vtx],node[idx]));
//            //printf("%d %d %d\n",vtx,idx,w[idx]);
//            q.push (make_pair (-1*w[idx],idx));
//            if(idx == finish){got=true; break;}
//        }
//    }
    if (visitable (y+1,x) ){
        w [y+1][x] = min (w[y+1][x] , max(w[y][x],node[y+1][x]));
        q.push (make_pair (-1 * w[y+1][x], make_pair(y+1,x)));
        if((y+1 == rb) && (x == cb)){got=true;}
    }
    if (visitable (y-1,x) ){
        w [y-1][x] = min (w[y-1][x] , max(w[y][x],node[y-1][x]));
        q.push (make_pair (-1 * w[y-1][x], make_pair(y-1,x)));
        if((y-1 == rb) && (x == cb)){got=true;}
    }
    if (visitable (y,x+1) ){
        w [y][x+1] = min (w[y][x+1] , max(w[y][x],node[y][x+1]));
        q.push (make_pair (-1 * w[y][x+1], make_pair(y,x+1)));
        if((y == rb) && (x+1 == cb)){got=true;}
    }
    if (visitable (y,x-1) ){
        w [y][x-1] = min (w[y][x-1] , max(w[y][x],node[y][x-1]));
        q.push (make_pair (-1 * w[y][x-1], make_pair(y,x-1)));
        if((y == rb) && (x-1 == cb)){got=true;}
    }
}
void dijkstra(){
    w[ra][ca]=0;
    q.push(make_pair(w[ra][ca],make_pair(ra,ca)));
    while(!q.empty()){
        int ty = q.top().second.first;
        int tx = q.top().second.second;
        //printf("%d\n",t);
        if ((ty == rb) && (tx == cb)) {break;}
        q.pop();
        if(!vis[ty][tx]){
            vis[ty][tx]=true;
            relax(ty,tx);
            if(got){break;}
        }
    }
}
int main(){
    scanf("%d %d",&r,&c);
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            scanf("%d",&node[i][j]);
        }
    }
    scanf("%d %d",&ra,&ca);
    scanf("%d %d",&rb,&cb);

    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            w[i][j] = INF;

    dijkstra();
    printf("%d\n",w[rb][cb]);
}
