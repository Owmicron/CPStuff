#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,m,p[1000000];
ll calculate(ll x){
    ll a=0;
    for(ll i=1;i<=n;i++){
        a+=x/p[i];
    }
    return a;
}
ll src1(){
    ll l=1;
    ll r=10000000000000;
    ll mid=(l+r)/2;bool found=false;
    while((l<=r)&&(!found)){
        mid=(l+r)/2;
        ll y = calculate(mid-1);
        ll z = calculate(mid);
        if(z==m){
            if(y!=m){found=true;}
            else{r=mid-1;}
        }
        else if(z>m){r=mid-1;}
        else if(z<m){l=mid+1;}
    }
    if(!found){return 0;}
    return mid;
}
ll src2(){
    ll l=1;
    ll r=10000000000000;
    ll mid=(l+r)/2;bool found=false;
    while((l<=r)&&(!found)){
        mid=(l+r)/2;
        ll y = calculate(mid+1);
        ll z = calculate(mid);
        if(z==m){
            if(y!=m){found=true;}
            else{l=mid+1;}
        }
        else if(z>m){r=mid-1;}
        else if(z<m){l=mid+1;}
    }
    if(!found){return 0;}
    return mid;
}
int main(){
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>p[i];
    }

    ll ansa,ansb;
    ansa=src1();ansb=src2();
    if((ansa==0)||(ansb==0)){cout<<0<<endl;}
    else{
        cout<<ansb-ansa+1<<endl;
    }
}
