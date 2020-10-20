#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,m,a[30][30],score,ans,rx,ry;
bool visited[30][30],crushed[30][30];
ll dfs(ll y, ll x, ll b){
    if((y>=1)&&(y<=n)&&(x>=1)&&(x<=m)){
        if(!visited[y][x]){
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
                    runtuh =true;
                }
            }
        }
    }
    if(runtuh){collapse();}
}
int main(){
    ans=-1;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            score=0;
            dfs(i,j,a[i][j]);
            score = score*(score-1);
            if(score>ans){ans=score;ry=i;rx=j;}
        }
    }
    destroy(ry,rx,a[ry][rx]);
    collapse();
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(!crushed[i][j]){cout<<a[i][j];}
            else{cout<<".";}
            if(j<m){cout<<" ";}
            else{cout<<"\n";}
        }
    }

}
