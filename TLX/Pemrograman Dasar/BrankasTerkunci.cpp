#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
bool used[10];
void c(ll n,ll k,ll deep){
    for(ll i=deep; i<=(deep + abs(n-k)); i++){
        if(!used[i]){
            used[i]=true;

            bool can=true;
            for(ll j=i+1;j<=n;j++){
                if (used[j]){can=false;break;}
            }
            if(!can){used[i]=false;continue;}

            if(deep<k){c(n,k,deep+1); used[i]=false;}
            else{
                ll f=0;
                for(ll i=1;i<=9;i++){
                    if(used[i]){
                        cout<<i;f++;
                        if(f<k){cout<<" ";}
                        else{cout<<endl;}
                    }
                }

                used[i]=false;
            }
        }
    }
}
int main(){
    ll a,b;
    cin>>a>>b;
    c(a,b,1);
}
