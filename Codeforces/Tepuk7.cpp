#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll memo[1001];
bool is7(ll x){
    if( x % 7 == 0){return true;}
    else{
        ll dv=10;
        while(x > 0){
            if (x % dv == 7){return true;}
            else{
                x-= (x%dv);
                x/=dv;
            }
        }
    }
    return false;
}
int t;
ll c,n;
bool p;
void fwd(){
    c++;if(c>n){c=1;}
}
void bwd(){
    c--;if(c<1){c=n;}
}


int main(){
    for(ll i=1;i<=1000;i++){
        memo[i]=is7(i);
    }
    cin>>t;
    for(ll i=1;i<=t;i++){
        cin>>n;
        c=0;p=true;
        for(ll j=1;j<=n;j++){
           if(p){fwd();}
           else{bwd();}
           if(memo[j]){
                p=not p;
           }
        }
        cout<<c<<endl;

    }



}
