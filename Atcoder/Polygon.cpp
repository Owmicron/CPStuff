#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,l[200],sum;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>l[i];
    sort(l+1,l+1+n);
    for(int i=1;i<n;i++)sum+=l[i];
    if(l[n]<sum){cout<<"Yes\n";}
    else{cout<<"No\n";}
}
