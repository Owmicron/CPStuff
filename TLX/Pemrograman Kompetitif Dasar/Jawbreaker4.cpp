#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,m,p[30][30],a[30][30],score,ans,rx,ry,score1,score2;
bool visited[30][30],crushed[30][30];
void reset(){
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            a[i][j]=p[i][j];
            visited[i][j]=false;
            crushed[i][j]=false;
        }
    }
}
ll dfs(ll y, ll x, ll b){
    if((y>=1)&&(y<=n)&&(x>=1)&&(x<=m)){
        if((!visited[y][x])&&(!crushed[y][x])){
            if(a[y][x]==b){
                score++;
                visited[y][x]=true;
                dfs(y+1,x,b);
                dfs(y-1,x,b);
                dfs(y,x+1,b);
                dfs(y,x-1,b);
            }
        }
    }
}
void destroy(ll y,ll x,ll b){
    if((y>=1)&&(y<=n)&&(x>=1)&&(x<=m)){
        if(!crushed[y][x]){
            if(a[y][x]==b){
                crushed[y][x]=true;
                destroy(y+1,x,b);
                destroy(y-1,x,b);
                destroy(y,x+1,b);
                destroy(y,x-1,b);
            }
        }
    }
}
void collapse(){
    bool runtuh = false;
    for(ll i=1;i<n;i++){
        for(ll j=1;j<=m;j++){
            if(!crushed[i][j]){
                if(crushed[i+1][j]){
                    swap(crushed[i][j],crushed[i+1][j]);
                    swap(a[i][j],a[i+1][j]);
                    swap(visited[i][j],visited[i+1][j]);
                    runtuh =true;
                }
            }
        }
    }
    if(runtuh){collapse();}
}
int main(){
    ans=0;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin>>p[i][j];
        }
    }
    score2=0;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            reset();
            score=0;
            dfs(i,j,a[i][j]);
            score1 = score*(score-1);
            destroy(i,j,a[i][j]);
            collapse();
            if(score1>ans){ans=score1;}
            for(ll ii=1;ii<=n;ii++){
                for(ll jj=1;jj<=m;jj++){
                    if((i==ii)&&(j==jj)){continue;}
                    else{
                        if((!crushed[ii][jj])){
                            score=0;score2=0;
                            dfs(ii,jj,a[ii][jj]);
                            score2 = score*(score-1);
                            if(score1+score2>ans){
                                ans=score1+score2;
                                //cout<<i<<j<<" "<<ii<<jj<<" "<<score1<<""<<score2<<endl;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}
