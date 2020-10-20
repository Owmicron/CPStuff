#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,a[200000];
ll mn,sum;
bool neg;
int main(){
    cin>>n;
    mn = 1000000000;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<0)neg=not neg;
        sum += abs(a[i]);
        mn = min(mn,abs(a[i]));
    }
    if(neg)sum-=2*mn;
    cout<<sum<<endl;
}
