#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,x[1000],e,o;
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>x[i];
        if(x[i]%2==0){e++;}
        else{o++;}
    }

    if(e==1){
        for(ll i=1;i<=n;i++){
            if(x[i]%2==0){cout<<i;break;}
        }
    }
    else{
        for(ll i=1;i<=n;i++){
            if(x[i]%2==1){cout<<i;break;}
        }
    }


}
