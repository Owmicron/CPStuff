#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
double n,x,k,a,m[101],z;
int main(){
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        cin>>m[i];
        z+=m[i];
    }
    a=z/(n+x);

    if(a-trunc(a) < 0.5){a=trunc(a);}
    else{a=trunc(a)+1;}

    while(a<k){
        z+=k;x++;a=z/(n+x);

        if(a-trunc(a) < 0.5){a=trunc(a);}
        else{a=trunc(a)+1;}
    }
    cout<<x;



}
