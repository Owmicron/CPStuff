#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
map <ll,ll> f;
ll n,m;
ll b[100010],g[100010];
unsigned long long sum;
bool fals[100100];
priority_queue<int> qb,qg;
int main(){
    cin>>n>>m;
    ll mxb,mng;
    mxb=-1;mng=INT_MAX;
    for(int i=1;i<=n;i++){
        cin>>b[i];
        mxb = max(b[i],mxb);
        f[b[i]]++;

    }
    for(int i=1;i<=m;i++){
        cin>>g[i];
        if(f[g[i]]>0){
            f[g[i]]--;
            fals[i]=true;
        }
        mng = min(g[i],mng);
    }

    if(mxb>mng){
        cout<<-1<<endl;
    }
    else{
        for(int i=1;i<=n;i++){
            f[b[i]]=0;
        }
        for(int i=1;i<=n;i++){
            if(f[b[i]]==0){
                qb.push(b[i]);
            }
            f[b[i]]+=m-1;
            sum+=b[i]*m;
        }

        for(int i=1;i<=m;i++){
            if(!fals[i]){
                qg.push(g[i]);
            }
        }
        while(!qg.empty()){
            ll girl = qg.top();
            ll boy = qb.top();
            f[boy]--;
            if(f[boy]==0){qb.pop();}
            sum-=boy;
            sum+=girl;
            qg.pop();
        }
        cout<<sum<<endl;

    }

}
