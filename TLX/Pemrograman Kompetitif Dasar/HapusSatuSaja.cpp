#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str a,b;
bool can(str x,str y){
    for(ll i=0;i<x.size();i++){
        str z=x;
        z.replace(i,1,"");
        if(z==y){return true;}
    }
    return false;
}
int main(){
    cin>>a;cin>>b;
    if(can(a,b)){cout<<"Tentu saja bisa!"<<endl;}
    else{cout<<"Wah, tidak bisa :("<<endl;}
}
