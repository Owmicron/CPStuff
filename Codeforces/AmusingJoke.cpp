#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str a,b,c;
bool used[101];
bool ok(char x){
    for(ll i=0;i<c.size();i++){
        if(!used[i]){
            if(x==c[i]){used[i]=true;return true;}
        }
    }
    return false;
}
bool ans=true;;
int main(){
    cin>>a;cin>>b;cin>>c;
    for(ll i=0;i<a.size();i++){
        if(!ok(a[i])){ans=false;break;}
    }

    if(ans){

    for(ll i=0;i<b.size();i++){
        if(!ok(b[i])){ans=false;break;}
    }

    }

    if((a.size()+b.size())!=c.size()){ans=false;}
    if(ans){cout<<"YES";}
    else{cout<<"NO";}
}
