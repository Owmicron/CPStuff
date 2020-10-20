#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n;
int main(){
    cin>>n;
    if(n>=0){cout<<n<<endl;}
    else{
        ll a,b;
        n=abs(n);
        a = (n/10)%10;
        b = n%10;
        //cout<<a<<" "<<b<<endl;
        if(a>b){n = ((n- 10*a) /10) + b;}
        else{n-=b;n/=10;}
        n*=-1;
        cout<<n<<endl;

    }
}
