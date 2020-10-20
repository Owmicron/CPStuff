#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll p[300000],n,t[300000];
int main(){
    cin>>n;
    p[1]=1;
    for(int i=1;i<n;i++){
        ll q;
        cin>>q;
        p[i+1]=p[i]+q;
    }
    ll mn = 1000000000000000;
    for(int i=1;i<=n;i++){
        mn = min(mn,p[i]);
    }
    ll gap = 1-mn;
    for(int i=1;i<=n;i++){
        p[i]+=gap;
    }
    for(int i=1;i<=n;i++)t[i]=p[i];
    sort(t+1,t+1+n);
    bool valid=true;
    for(int i=1;i<=n;i++){
        if(t[i]!=i){valid=false;break;}
    }
    if(valid){
        for(int i=1;i<=n;i++){
            cout<<p[i];
            if(i<n)cout<<" ";
        }cout<<endl;
    }
    else cout<<-1<<endl;
}
