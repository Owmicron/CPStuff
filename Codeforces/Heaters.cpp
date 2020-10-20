#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,r,a[2000],c,ans;
bool z,light[2000];
void on(ll x){
    ll mx=0;
    for(ll i=x;i<=x+r-1;i++){
        if(a[i]==1){
            mx=i;
        }
    }
    //cout<<"mx"<<mx<<endl;
    if(mx==0){
        ll mn=0;
        for(ll i=x;i>=x-r+1;i--){
            if(i<1){break;}
            if(a[i]==1){
                mn=i;
            }
        }
        //cout<<"mn"<<mn<<endl;
        if(mn==0){z=false;}
        else{
            for(ll i=mn-r+1;i<=mn+r-1;i++){
                if(i<1){continue;}
                else{light[i]=true;}
            }
            c = mn+r-1;
        }
    }
    else{
        for(ll i=mx-r+1;i<=mx+r-1;i++){
            if(i<1){continue;}
            else{light[i]=true;}
        }
        c= mx+r-1 ;
    }


}
int main(){
    cin>>n>>r;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }

    z=true;
    while(c<n){
        c++;
        //cout<<c<<endl;
        on(c);
        if(!z){break;}
        else{ans++;}
    }
    if(!z){ans=-1;}
    cout<<ans<<endl;

}
