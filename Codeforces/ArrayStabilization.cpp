#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int a[200000],n,ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    ans = min(a[n]-a[2] , a[n-1]-a[1]);
    cout<<ans;


}
