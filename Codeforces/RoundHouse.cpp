#include<bits/stdc++.h>
using namespace std;
int main(){

    int n,a,b;
    cin>>n>>a>>b;
    if (b<0){b= n+(b%n) ;}
    int res;
    res = (a + b) % n;
    if (res==0){cout<<n;}
    else{cout<<res;}

}
