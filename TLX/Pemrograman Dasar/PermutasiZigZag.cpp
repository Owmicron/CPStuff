#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll w[10];
bool used[10];
bool isz(ll a, ll b, ll c){
    if(((b<a)&&(b<c))||((b>a)&&(b>c))){
        return true;
    }
    return false;
}
void p(ll deep, ll x){
    for(ll i=1;i<=x;i++){
        if(!used[i]){
            w[deep]=i;
            used[i]=true;

            if(deep>2){
                if(!isz(w[deep-2],w[deep-1],w[deep])){
                    used[i]=false;
                    continue;
                }
            }

            if(deep<x){p(deep+1,x);}
            else{
                for(ll i=1;i<=x;i++){
                    cout<<w[i];
                }
                cout<<endl;
            }
            used[i]=false;
        }
    }
}

int main(){
    ll n;
    cin>>n;
    p(1,n);

}
