#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll a;
str ans;
int main(){
    ll a,b;
    cin>>a>>b;

    ll n1,n2;

    n1 = ((a - 1)/2)+1;
    n2 = ((b - 2)/2)+1;

    n1 = 1 + (n1 - 1)*2;
    n2 = 2 + (n2 - 1)*2;
    bool wins;

    if(n1>n2){
        wins=true;
    }
    else{
        wins=false;
    }

    cout<<n1<<" "<<n2;
    if (wins){cout<<"Vladik";}
    else{cout<<"Valera";}




}
