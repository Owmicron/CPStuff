#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,m;
stack < pair<int,int> > bridge;
int parent[200000],sz[200000];
ll sum;
stack<ll> ans;
ll C2 (ll x){
    ll res = (x*(x-1))/2;
    return res;
}
int findrep(int x){
    if(parent[x]==x) return parent[x];
    else{
        return findrep (parent[x]);
    }
}
void join (int a, int b){
    int repa,repb;
    repa = findrep(a);
    repb = findrep(b);
    if(repa>repb)swap(repa,repb);
    parent[repb]=repa;
    sz[repa] = sz[repa] + sz[repb];
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        if(a>b){swap(a,b);}
        bridge.push(make_pair(a,b));
    }
    for(int i=1;i<=n;i++){parent[i]=i;sz[i]=1;}
    sum = C2(n);
    ans.push(sum);
    while(!bridge.empty()){
        int a = bridge.top().first;
        int b = bridge.top().second;
        bridge.pop();
        int para,parb;
        para = findrep(a);
        parb = findrep(b);

        if(para!=parb){
            sum += C2(sz[para]);
            sum += C2(sz[parb]);
            sum -= C2(sz[para]+sz[parb]);
            join(para,parb);
            //cout<<C2(sz[para])<<" "<<C2(parb)<<" "<<C2(para+parb)<<endl;
        }
        ans.push(sum);
    }
    ans.pop();
    while(!ans.empty()){
        cout<<ans.top()<<endl;
        ans.pop();
    }
}
