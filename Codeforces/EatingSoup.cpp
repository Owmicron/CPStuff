#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,m;
int nex[2000],pre[2000];
bool ava[2000];
int main(){
    cin>>n>>m;
    for(int i=1;i<n;i++){
        nex[i]=i+1;
    }
    nex[n]=1;
    for(int i=2;i<=n;i++){
        pre[i]=i-1;
    }
    pre[1]=n;

    int idx=1;
    for(int i=1;i<=n;i++)ava[i]=true;
    for(int i=1;i<=m;i++){
        idx = nex[idx];
        idx = nex[idx];
        ava[idx]=false;

        nex[pre[idx]] = nex[idx];
        pre[nex[idx]] = pre[idx];

    }

    int f=0;
    for(int i=1;i<n;i++){
        if(ava[i] && !ava[i+1]){
            f++;
        }
    }
    if( ava[n] && !ava[1]){f++;}

    if(f==0){
        if(n==m){f=0;}
        else{f=1;}
    }
    cout<<f<<endl;
}
