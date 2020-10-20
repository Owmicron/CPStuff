#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll gcd(ll x , ll y){
    if(x==0){return y;}
    else if(y==0){return x;}
    else{
        if(x<y){swap(x,y);}
        ll z = -1;

        while(z!=0){
            z = x%y;

            if(z!=0){
                x=y;
                y=z;
            }

        }
        return y;


    }
}
bool turn;
int main(){
    ll a,b,n;
    cin>>a>>b>>n;

    while(n>=0){
        turn=not turn;
        if(turn){n-=gcd(a,n);}
        else{n-=gcd(b,n);}

    }
    if(turn){cout<<1;}
    else{cout<<0;}

}
