#include<bits/stdc++.h>
using namespace std;


int main(){

        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

        
    long long k2,k3,k5,k6;
    long long a=0,b=0;
    long long big=100000000000;
    cin>>k2>>k3>>k5>>k6;

    if(k2 > 0 && k5>0 && k6>0){
        a=big;
        if (k2 < a){a=k2;}
        if (k5 < a){a=k5;}
        if (k6 < a){a=k6;}
    }

    k2-=a;
    k5-=a;
    k6-=a;

    if(k3 > 0 && k2>0){
        b=big;
        if(k2 < b){b=k2;}
        if(k3 < b){b=k3;}

    }

    cout<<a*256+b*32;
}
