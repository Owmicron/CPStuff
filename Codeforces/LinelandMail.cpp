#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,x[200000];
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>x[i];
    cout<<abs(x[2]-x[1])<<" "<<abs(x[n]-x[1])<<endl;
    for(ll i=2;i<n;i++){
        ll mn,mx;
        mn = min(abs(x[i]-x[i-1]),abs(x[i]-x[i+1]));
        mx = max(abs(x[i]-x[1]),abs(x[i]-x[n]));
        cout<<mn<<" "<<mx<<endl;
    }
    cout<<abs(x[n]-x[n-1])<<" "<<abs(x[n]-x[1])<<endl;
}
