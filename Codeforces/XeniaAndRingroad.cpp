#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,m,tar,pos,ans;
int main(){
    ll n,m;
    cin>>n>>m;
    pos=1;
    for(ll i=1;i<=m;i++){
        cin>>tar;
        if(pos<tar){ans+=tar-pos;}
        else if(pos==tar){}
        else{ans+=(n-pos+tar);}

        pos=tar;
    }
    cout<<ans<<endl;
}



