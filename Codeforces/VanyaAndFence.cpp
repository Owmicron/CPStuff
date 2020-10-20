#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,h,ans;
int main(){
    cin>>n>>h;
    for(ll i=1;i<=n;i++){
        ll temp;
        cin>>temp;

        if(temp>h){ans+=2;}
        else{ans++;}

    }
    cout<<ans<<endl;
}


