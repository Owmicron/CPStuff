#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n;
int main(){
    cin>>n;
    if(n%2==0){
        if(n%4==0){cout<<0;}
        else{cout<<1;}
    }
    else{
        if(n==1){cout<<1;}
        else if((n-3)%4 ==0){cout<<0;}
        else{cout<<1;}
    }


}
