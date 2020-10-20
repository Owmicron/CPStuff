#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll x,y,n,w,b;
int main(){
    cin>>n;
    cin>>x>>y;
    w = max(x-1,y-1);
    b = max(n-x,n-y);
    if(b>w){cout<<"White";}
    else{cout<<"Black";}

}
