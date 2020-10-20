#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int main(){
    str s;
    cin>>s;
    ll temp=1;
    ll n=0;
    for(ll i=1;i<=4;i++){
        if(s.size() >= i){
            n+= (temp* ( int(s[s.size()-i]) - 48 ));
        }
        temp*=10;
    }
    //cout<<n<<endl;
    ll ans;
    if(n%4==0){ans=4;}
    else{ans=0;}


    cout<<ans<<endl;
}





