#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int r,c,start,fin,n;
int INF = 10000000;
bool rock[1010][1010],used[1010][1010],vis[1010];
int par[1000010],address[1000010],dist[1010];
priority_queue <pair <int,int> > q;
vector < pair <int,int> > adj[1010];
pair <int, int> to_cart(int z){
    int y,x;
    y = ((z/c)+1);
    if(z%c==0){y--;}
    x = z%c;
    if(x==0){x=c;}
    return make_pair (y,x);
}
int to_node (int y, int x){
    return (y-1)*c + x;
}
int find_parent(int x){
    if(par[x] == x){
        return x;
    }
    else{
        par[x] = find_parent (par[x]);
        return par[x];
    }
}
void join (int a,int b){
    int pa = find_parent(a);
    int pb = find_parent(b);
    par[pb]=par[pa];
}
bool same_pieces(int a,int b){
    int pa=find_parent(a);
    int pb=find_parent(b);
    if(par[pa]==par[pb]){return true;}
    else{return false;}
}
void dijkstra(){
    q.push(make_pair(0,start));
    dist [start] = 0;
    while(!q.empty()){
            int node;
            node = q.top().second;
            q.pop();
            if(!vis[node]){
                vis[node] = true;
                for(int i=0;i<adj[node].size();i++){
                    int target = adj[node].at(i).first;
                    if (dist[target] > dist[node] + adj[node].at(i).second){
                        dist[target] = dist[node] + adj[node].at(i).second;
                        q.push (make_pair(dist[target]*-1 , target));
                    }
                }
            }
    }
}
int main(){
    scanf("%d %d",&r,&c);
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            char c;
            cin>>c;
            if(c!='.'){
                par[to_node(i,j)] = to_node(i,j);
                if(c == 'S'){start = to_node(i,j);}
                if(c == 'T'){fin = to_node(i,j);}
                rock[i][j]=true;
            }
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(i>1){
                if(rock[i][j] && rock[i-1][j]){
                    int ta,tb;
                    ta = to_node(i-1,j);
                    tb = to_node(i,j);
                    join(ta,tb);
                }
            }
            if(j>1){
                if(rock[i][j] && rock[i][j-1]){
                    int ta,tb;
                    ta = to_node (i,j-1);
                    tb = to_node (i,j);
                    join(ta,tb);
                }
            }
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            int x=to_node(i,j);
            find_parent(x);
            if(par[x] == x){n++;address[par[x]]=n;}
        }
    }

    for(int i=1;i<=r;i++){
        int val = 0;
        int idx = 0;
        for(int j=1;j<=c;j++){
            if(!rock[i][j]){
                val=1;
            }
            else{
                if(idx>0){
                    if(val>0){
                        int ta,tb;
                        ta = idx;
                        tb = to_node(i,j);
                        find_parent(ta);find_parent(tb);
                        if(!used[address[par[ta]]][address[par[tb]]] || !used[address[par[tb]]][address[par[ta]]]){
                            adj[address[par[ta]]].push_back(make_pair(address[par[tb]],val));
                            adj[address[par[tb]]].push_back(make_pair(address[par[ta]],val));
                            used[address[par[ta]]][address[par[tb]]]=true;
                            used[address[par[tb]]][address[par[ta]]]=true;
                        }
                    }
                }
                idx = to_node(i,j);
                val = 0;
            }
        }
    }
    for(int j=1;j<=c;j++){
        int val = 0;
        int idx = 0;
        for(int i=1;i<=r;i++){
            if(!rock[i][j]){
                val=1;
            }
            else{
                if(idx>0){
                    if(val>0){
                        int ta,tb;
                        ta = idx;
                        tb = to_node(i,j);
                        find_parent(ta);find_parent(tb);
                        if(!used[address[par[ta]]][address[par[tb]]] || !used[address[par[tb]]][address[par[ta]]]){
                            adj[address[par[ta]]].push_back(make_pair(address[par[tb]],val));
                            adj[address[par[tb]]].push_back(make_pair(address[par[ta]],val));
                            used[address[par[ta]]][address[par[tb]]]=true;
                            used[address[par[tb]]][address[par[ta]]]=true;
                        }
                    }
                }
                idx = to_node(i,j);
                val = 0;
            }
        }
    }
//    for(int i=1;i<=r;i++){
//        for(int j=1;j<=c;j++){
//            cout<<address[find_parent(to_node(i,j))]<<" ";
//        }
//        cout<<endl;
//    }
//    for(int i=1;i<=n;i++){
//        cout<<"rock "<<i<<endl;
//        for(int j=0;j<adj[i].size();j++){
//            cout<<adj[i].at(j).first<<endl;
//        }
//    }
    for(int i=1;i<=n;i++)dist[i]=INF;
    start = address[find_parent(start)];
    fin = address[find_parent(fin)];
//    cout<<endl<<start<<endl<<fin<<endl<<endl;
    dijkstra();
    if(dist[fin]>=INF){dist[fin]=-1;}
    printf("%d\n",dist[fin]);

}
