#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,c[30],v[30],ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>v[i];
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++){
        if(v[i]-c[i]>0){ans+=v[i]-c[i];}
    }
    cout<<ans<<endl;
}
