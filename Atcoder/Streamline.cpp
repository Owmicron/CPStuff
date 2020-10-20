#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
priority_queue<int> q;
ll ans;
int n,m,x[200000];
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>x[i];
    sort(x+1,x+1+m);
        for(int i=2;i<=m;i++){
            q.push(x[i]-x[i-1]);
        }
    for(int i=1;i<n;i++){
        if(!q.empty())q.pop();
    }
    while(!q.empty()){
        ans+=q.top();
        q.pop();
    }
    cout<<ans<<endl;
}
