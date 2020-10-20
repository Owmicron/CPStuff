#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,x,ans;

int main(){
    cin>>n>>x;
    for(ll i=1;i<=sqrt(x);i++){
        if(i>n){break;}
        else{
            if(x%i == 0){
                 if((x/i)<=n){ans++;}
            }
        }
    }
    ans*=2;
    if(sqrt(x)==floor(sqrt(x))){ans--;}
    if(ans<0){ans=0;}
    cout<<ans<<endl;
}
