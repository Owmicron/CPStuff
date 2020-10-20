#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,m;
pair <ll,ll> vertex[300000];
ll x,y,w,cost,par[300000];
priority_queue < pair < ll, pair<ll,ll> > > q;
ll parent(ll x){
    if(par[x] == x){return x;}
    else{
        par[x] = parent(par[x]);
        return par[x];
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll temp;cin>>temp;
        vertex[i] = make_pair(temp,i);
    }
    for(int i=1;i<=m;i++){
        cin>>x>>y>>w;
        if(x>y)swap(x,y);
        q.push( make_pair (-1*w , make_pair (x,y) ));

    }
    sort(vertex+1,vertex+1+n);

    for(int i=2;i<=n;i++){
        ll a,b,p;
        a = vertex[1].second;
        b = vertex[i].second;
        p = vertex[1].first + vertex[i].first;
        if(a>b)swap(a,b);
        q.push (make_pair(-1*p , make_pair(a,b)) );
    }
    for(int i=1;i<=n;i++)par[i]=i;
    while(!q.empty()){
        ll a,b,w;
        a = q.top().second.first;
        b = q.top().second.second;
        w = q.top().first * -1;
        ll pa,pb;
        pa = parent(a);
        pb = parent(b);
        if(pa != pb){
            par[pb] = pa;
            cost += w;
        }
        q.pop();
    }
    cout<<cost<<endl;

}
