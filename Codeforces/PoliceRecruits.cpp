#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,ans,p;
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        ll temp;cin>>temp;
        if(temp==-1){
            p--;if(p<0){p=0;ans++;}
        }
        else{p+=temp;}
    }
    cout<<ans<<endl;
}
