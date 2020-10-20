#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int INF = 1000000000;
int n,m,q,w[300][300],dist[300][300],p[300];
ll ans;
void floyd_warshall(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j] = w[i][j];
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}
int main(){
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            w[i][j]=INF;
        }
    }
    for(int i=1;i<=n;i++){
        w[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        w[a][b]=min(w[a][b],c);w[b][a]=min(w[b][a],c);
    }
    floyd_warshall();
    for(int i=1;i<=q;i++){
        cin>>p[i];
    }
    for(int i=2;i<=q;i++){
        ans+=dist[p[i-1]][p[i]];
    }
    cout<<ans<<endl;
}
