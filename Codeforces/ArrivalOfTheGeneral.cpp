#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,a[101],mx,mn,ans;
int main(){
    cin>>n;mn=101;mx=-1;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>mx){mx=a[i];}
        if(a[i]<mn){mn=a[i];}
    }

    for(ll i=n;i>=1;i--){
        if(a[i]==mn){
            for(ll j=i;j<n;j++){
                swap(a[j],a[j+1]);
                ans++;
            }
            break;
        }
    }

    for(ll i=1;i<=n;i++){
        if(a[i] == mx){
            for(ll j=i;j>1;j--){
                swap(a[j],a[j+1]);
                ans++;
            }
            break;
        }
    }
    cout<<ans;
}
