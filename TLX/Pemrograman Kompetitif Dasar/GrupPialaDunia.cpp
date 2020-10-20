#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll t,n,deep[100],p,g[100],c[200],matches,score[100];
bool ans;
void play(){
    matches=0;
    for(ll i=1;i<=n;i++){
        g[i]=0;
    }
    for(ll i=1;i<n;i++){
        for(ll j=i+1;j<=n;j++){
            //cout<<i<<j<<endl;
            matches++;
            if(deep[matches]==1){g[i]+=3;}
            else if(deep[matches]==2){g[j]+=3;}
            else{g[i]++;g[j]++;}
        }
    }
    bool test=true;
    for(ll i=1;i<=n;i++){
        //cout<<g[i];
        if(g[i]!=score[i]){test=false;break;}
    }
    if(test){ans=true;}
    //cout<<endl;

}
void guess(ll x){
    if(x>=1){
        for(ll i=1;i<=3;i++){
            deep[x]=i;
            if(x==1){
//                for(ll j=1;j<=n;j++){
//                    cout<<deep[j];
//                }
//                cout<<endl;
                play();

            }
            else{guess(x-1);}
        }
    }
}

int main(){
    cin>>t;
    for(ll cs=1;cs<=t;cs++){
        cin>>n;
        //guess(n);
        ans=false;
        for(ll i=1;i<=n;i++){cin>>score[i];}
        guess(n*(n-1)/2);
        if(ans){cout<<"YES\n";}
        else{cout<<"NO\n";}
    }
}
