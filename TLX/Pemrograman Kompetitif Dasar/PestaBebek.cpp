#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,ans;
str s[1001];
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>s[i];
        ans=i;
        for(ll j=1;j<=i;j++){
            if(s[j]>s[i]){ans--;}
        }
        cout<<ans<<endl;
    }
}

