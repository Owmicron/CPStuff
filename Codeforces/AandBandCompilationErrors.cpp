#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll ans1,ans2,n,a[100001],b[100001];
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i=1;i<n;i++)cin>>b[i];
    sort(b+1,b+n);
    for(ll i=1;i<=n;i++){
        if(a[i]!=b[i]){ans1=a[i];break;}
    }
    for(ll i=1;i<n-1;i++)cin>>a[i];
    sort(a+1,a+n-1);
    a[n]=0;a[n-1]=0;
    for(ll i=1;i<=n;i++){
        if(a[i]!=b[i]){ans2=b[i];break;}
    }
    cout<<ans1<<endl<<ans2;

}
