#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,ans;
ll a[300];
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=2;i<n;i++){
        if(a[i]==0){
            if((a[i-1]==1)&&(a[i+1]==1)){a[i+1]=0;ans++;}
        }
    }
    cout<<ans<<endl;
}
