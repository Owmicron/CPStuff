#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,m,a[102],b[102],ans;
bool vis[102];
vector<int> adj[102];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    cin>>m;
    for(int i=1;i<=m;i++)cin>>b[i];
    sort(a+1,a+1+n);sort(b+1,b+1+m);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(abs(b[j]-a[i])<=1){adj[i].push_back(j);}
        }
    }
//    for(int i=1;i<=n;i++){
//        for(int j=0;j<adj[i].size();j++){
//            cout<<adj[i].at(j)<<" ";
//        }cout<<endl;
//    }
    for(int i=n;i>=1;i--){
        if(!adj[i].empty()){
            for(int j=adj[i].size()-1;j>=0;j--){
                if(!vis[adj[i].at(j)]){ans++;vis[adj[i].at(j)]=true;break;}
            }
        }
    }
    cout<<ans<<endl;
}
