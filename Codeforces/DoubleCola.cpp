#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,m;
ll ex[40];
bool calc[40];
str name (int x){
    if(x==1){return "Sheldon";}
    if(x==2){return "Leonard";}
    if(x==3){return "Penny";}
    if(x==4){return "Rajesh";}
    if(x==5){return "Howard";}
}
ll exp(ll x){
    if(x>0){
        if(!calc[x]){
            ll ans;
            ans = 2 * exp(x-1);
            calc[x]=true;
            ex[x]=ans;
            return ex[x];
        }
        else{return ex[x];}

    }
    else{return 1;}
}
ll ans;
int main(){

    cin>>n;
    while ( n - (5*exp(m)) > 0){
        n -= (5*exp(m));
        m++;
    }

    m=exp(m);

    for(ll i=1;i<=5;i++){
        if(n - m <= 0){ans=i;break;}
        n-=m;
    }

    cout<<name(ans)<<endl;


}
