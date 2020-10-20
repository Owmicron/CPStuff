#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
pair < deque<ll> , deque<ll> > v;
bool visited[102][102];
ll n,m,box[102][102],a,b,ans;
ll depth[102][102];
bool iscorner (ll xx,ll yy){
    if((xx==1)||(yy==1)||(xx==m)||(yy==n)) return true;
    else return false;
}
int main(){
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=m;j++)
            cin>>box[j][i];
    cin>>b>>a;

    v.first.push_back(a);
    v.second.push_back(b);
    visited[a][b]=true;

    depth[a][b]=1;

    while(!v.first.empty()){
        ll x,y;
        x = v.first.front();
        y = v.second.front();
        v.first.pop_front();
        v.second.pop_front();
        visited[x][y]=true;
        if(iscorner(x,y)){ans = depth[x][y];break;}
        else{
            if((box[x-1][y] == 0)&&(!visited[x-1][y])){
                v.first.push_back(x-1);
                v.second.push_back(y);
                depth[x-1][y] = depth[x][y]+1;
            }
            if((box[x][y-1] == 0)&&(!visited[x][y-1])){
                v.first.push_back(x);
                v.second.push_back(y-1);
                depth[x][y-1] = depth[x][y]+1;
            }
            if((box[x+1][y] == 0)&&(!visited[x+1][y])){
                v.first.push_back(x+1);
                v.second.push_back(y);
                depth[x+1][y] = depth[x][y]+1;
            }
            if((box[x][y+1] == 0)&&(!visited[x][y+1])){
                v.first.push_back(x);
                v.second.push_back(y+1);
                depth[x][y+1] = depth[x][y]+1;
            }
        }
    }
    cout<<ans<<endl;


}
