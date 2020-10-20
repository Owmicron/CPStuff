#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int par[100100],n,q;
int getpar(int x){
    if(par[x]==x)return x;
    else{
        par[x] = getpar(par[x]);
        return par[x];
    }
}
void check(int a, int b){
    if(getpar(a)==getpar(b))cout<<"Y"<<endl;
    else{cout<<"T"<<endl;}
}
void join(int a, int b){
    par[getpar(a)]=par[getpar(b)];
}

int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++)par[i]=i;
    for(int i=1;i<=q;i++){
        int com,a,b;cin>>com>>a>>b;
        if(com==1)join(a,b);
        else check(a,b);
    }
}
