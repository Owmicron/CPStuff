#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int main(){
    bool t=true;
    ll n;cin>>n;
    while(n>1){
        if(n%2 != 0){t=false;break;}
        n/=2;
    }
    if(t){cout<<"ya";}
    else{cout<<"bukan";}
    cout<<endl;
}
