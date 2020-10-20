#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll m,n,t[100][100],b,k,ans;
bool v[100][100];
void dfs(ll y, ll x){
    if((x<1)||(y<1)||(x>n)||(y>m)){

    }
    else{
        if(!v[y][x]){
            if(t[y][x]==t[b][k]){
                v[y][x]=true;ans++;
                dfs(y+1,x);
                dfs(y-1,x);
                dfs(y,x+1);
                dfs(y,x-1);
            }
        }
    }
}
int main(){
    cin>>m>>n;
    for(ll i=1;i<=m;i++){
        for(ll j=1;j<=n;j++){
            cin>>t[i][j];
        }
    }
    cin>>b>>k;b++;k++;
    dfs(b,k);
    cout<<ans*(ans-1)<<endl;

}



