#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll a,b,c,d,open,close,valid;
int main(){
    scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
    if(c>0){
        open = c + 2*a + b;
        close = c + 2*d + b;

        if(open==close){
            if(a>0)valid=true;
        }
    }
    else{
        open+=2*a + b;
        close+=b + 2*d;
        if(open==close){valid=true;}
    }
    cout<<valid;
}
