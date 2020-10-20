#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int main(){
    ll x,y;
    cin>>x>>y;
    if(x==y){cout<<"="<<endl;}
    else if(x > (pow(y,(x/(y*1.0))))){cout<<">"<<endl;}
    else if(x < (pow(y,(x/(y*1.0))))){cout<<"<"<<endl;}
}
