#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll a[60],ans,n;
int main(){
    ll mn = LONG_LONG_MAX;
    cin>>n;
    for(int i=0;i<5;i++){
        cin>>a[i];
        mn = min(mn,a[i]);
    }
    ans = n/mn;
    if(n%mn==0){ans--;}
    ans+=5;
    cout<<ans<<endl;

}
