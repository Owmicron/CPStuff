#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,m;
int parent[600000],sz[600000];
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

    if(repa!=repb){
        parent[repb]=repa;
        sz[repa] = sz[repa] + sz[repb];
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        parent[i]=i;sz[i]=1;
    }

    for(int i=1;i<=m;i++){
        int num;
        cin>>num;
        int leader;
        for(int i=1;i<=num;i++){
            int temp;
            cin>>temp;
            if(i==1){leader=temp;}
            else{
                join(leader,temp);
            }
        }
    }

    for(int i=1;i<=n;i++){
        int par;
        par = findrep(i);
        cout<<sz[par]<<" ";
    }
}
