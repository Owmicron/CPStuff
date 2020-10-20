#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll t,a;
int main(){
    cin>>t;
    for(ll i=1;i<=t;i++){
        cin>>a;
        if(360 % (180-a) == 0){cout<<"YES"<<endl;}
        else{cout<<"NO"<<endl;}
    }
}

