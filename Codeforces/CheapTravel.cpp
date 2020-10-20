#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll ans;
int main(){
    ll n,m,a,b;
    cin>>n>>m>>a>>b;
    if(n < m){
        ans = min(a*n,b);

    }
    else if((b/(m*1.0))<a){
        ans += (n/m)*b;
        if(n%m!=0){
            ans+= min ((n%m)*a , b );
        }
    }
    else{
        ans=n*a;
    }
    cout<<ans<<endl;
}

